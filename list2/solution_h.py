angles = list()
time = input()
while (time != "0:00"):
    hour, minute = [int(x) for x in time.split(":")]
    minute_angle = 360/60 * minute
    hour_angle = 360/12 * hour + 360/12/60 * minute

    angle_diff = abs(hour_angle - minute_angle)
    if angle_diff > 180:
        angle_diff = 360 - angle_diff
    angles.append(angle_diff)

    time = input()

for angle in angles:
    print(f"{angle:0.3f}")