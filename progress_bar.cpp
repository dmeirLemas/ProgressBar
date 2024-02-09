#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class ProgressBar {
	private:
		int total;
		int current;
		int bar_length;
		string message;

	public:
		ProgressBar(int total, int bar_length = 20, const string &message = "Finished!"): total(total), current(0), bar_length(bar_length), message(message) {
			std::cout << "\n\x1b[32m----Starting Program----\x1b[0m\n" << std::endl;
    }

		void update(int current) {
			double fraction = static_cast<double>(current) / total;

			string arrow;
			for (int i = 0; i < static_cast<int>(fraction * bar_length) - 1; ++i){
				arrow += "-";
			}
			arrow += ">";

			string padding;
			for (int i = 0; i < bar_length - arrow.size(); ++i){
				padding += " ";
			}

			string ending = current == total ? "\n\n" + message + "\n\n" : "\r";
			string completed = current == total ? "\x1b[32m" : "\x1b[0m";

			cout << completed << "Progress: [" << arrow << padding << "] " << fraction * 100 << "%" << ending;
		}

		void increment(int step = 1) {
			current += step;
			update(current);
		}

		void mark_as_completed() {
			current = total;
			update(current);
		}

		void simulateFileDownload() {
			auto startTime = std::chrono::high_resolution_clock::now();
			while (current < total) {
				auto currentTime = std::chrono::high_resolution_clock::now();
				auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
				if (elapsed >= 1) { // Update every 1 second
					increment(10);
					std::cout << std::flush; // Flush the output
					startTime = currentTime;
					startTime = currentTime;
				}
				// Simulate downloading work (replace this with actual work)
			}
		}
};

