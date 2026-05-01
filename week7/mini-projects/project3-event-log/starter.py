# starter.py — Event Log Reporter
# Project 3 | Intermediate | 35–45 minutes
#
# Run from this folder: 
#   python starter.py

import csv

# --- Step 1: Set up storage variables -----------------------
# store bookings and event counts
bookings = []
event_counts = {}

# --- Step 2: Read the CSV
# read CSV file
with open("bookings.csv", "r") as file:
    reader = csv.DictReader(file, skipinitialspace=True)
    # clean column names (remove spaces)
    reader.fieldnames = [field.strip() for field in reader.fieldnames]
# loop through each row
    for row in reader:
        # TODO: Get the event name from the row
        # get event name (handle different column names)
        event_name = row.get ("event" , row.get ("Event" , "Unknown")).strip()

        # TODO: Append event name to the bookings list
         # collect bookings
        bookings.append(event_name)

        # TODO: Increment the count for this event in event_counts
         # count events
        if event_name in event_counts:
            event_counts[event_name] += 1
        else:
            event_counts[event_name] = 1

# --- Step 3: Analyze the data -------------------------------
# TODO: Calculate total_bookings, most_popular, and least_popular
# calculate totals and popularity
total_bookings = len(bookings)

if event_counts:
    # find most and least popular
    most_popular = max(event_counts, key=event_counts.get)
    least_popular = min(event_counts, key=event_counts.get)
else:
    most_popular = "None"
    least_popular = "None"

# --- Step 4: Print the report -------------------------------
# print summary
print("=== event Booking Analysis ===")
print(f"{'Total Bookings:':<20} {total_bookings}")
print(f"{'Most Popular:':<20} {most_popular} ({event_counts.get(most_popular,0)} bookings)")
print(f"{'Least Popular:':<20} {least_popular} ({event_counts.get(least_popular,0)} bookings)")

print("\n--- Bookings per Event ---")
# print each event count
for event, count in event_counts.items():
    print(f"{event:<20}: {count}")

print("\n" + "-" * 30)
