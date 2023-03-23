TODO:

- [x] Check the number of arguments
- [x] Check the first line of input.txt is "date | value"
- [x] Check date is valid on each line (Year-Month-Day)
- [x] Check value is valid on each line (0 <= x <= 1000)
- [x] Implement a function that picks the previous date if the date in input.txt is not in data.csv (check year, month, then day)
- [x] Assign different error codes depending on the errors you can find in the exercise
	- _stod/_dtos conversion has failed				1
	- date format is invalid						2
	- delimiter is invalid " | " <- I mean that		3
	- value is invalid (value < 0)					4
	- value is invalid (value > 1000)				5

- [x] solve segfault when using upper_bound

- [ ] Create .cpp file and move functions there
- [ ] Clean your mess