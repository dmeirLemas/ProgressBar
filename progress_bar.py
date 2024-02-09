#!/opt/homebrew/bin/python3

import sys
import time
class ProgressBar:
	def __init__(self, total: int, bar_length=20, done_message="Finished!", update_interval=1):
		self.total = total
		self.bar_length = bar_length
		self.done_message = done_message
		self.update_interval = update_interval
		self.current = 0

		print("\n\x1b[32m----Starting Program----\x1b[0m\n")

	def update(self, current: int):
		self.current = current
		fraction = self.current / self.total

		arrow = int(fraction * self.bar_length - 1) * '-' + '>'
		padding = (self.bar_length - len(arrow)) * ' '

		if self.current == self.total:
			ending = f'\n\n{self.done_message}\n\n'
		else:
			ending = '\r'

		completed = '\x1b[32m' if self.current == self.total else '\x1b[0m'

		print(
		f"{completed}Progress: [{arrow}{padding}] {int(fraction*100)}%",
		end=ending
		)

	def increment(self, step=1):
		self.update(self.current + step)

# Example usage
total_items = 100
progress_bar = ProgressBar(total_items)

for i in range(total_items + 1):
	try:
		progress_bar.increment()
		time.sleep(0.1)  # Simulate some processing time
	except KeyboardInterrupt:
		sys.stdout.write("\x1b[2K")
		sys.stdout.write("\x1b[31mCancelled...\x1b[0m\n\n")
		sys.stdout.flush()
		exit()
