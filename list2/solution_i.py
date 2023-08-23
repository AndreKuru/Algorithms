from datetime import date, timedelta

dates = list()
tests_amount = int(input())
for _ in range(tests_amount):
    year, month, day = input().split('-')
    increase_days = int(input())
    year = int(year)
    day = int(day)
    match month:
        case "January":
            month = 1
        case "February":
            month = 2
        case "March":
            month = 3
        case "April":
            month = 4
        case "May":
            month = 5
        case "June":
            month = 6
        case "July":
            month = 7
        case "August":
            month = 8
        case "September":
            month = 9
        case "October":
            month = 10
        case "November":
            month = 11
        case "December":
            month = 12
    
    input_date = date(year, month, day)
    input_date
    dates.append(input_date + timedelta(increase_days))

for i in range(len(dates)):
    increased_date:date = dates[i]
    print(f"Case {i + 1}: {increased_date.strftime('%Y-%B-%d')}")