# starter.py — Event Log Reporter

import csv

# Step 1: Data structures
room_counts = {}
type_counts = {}
day_attendees = {}
all_events = []

# Step 2: Read CSV (single pass)
with open("bookings.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        room = row["room"]
        event_type = row["event_type"]
        date = row["date"]
        attendees = int(row["attendees"])

        # Update room counts
        if room in room_counts:
            room_counts[room] += 1
        else:
            room_counts[room] = 1

        # Update event type counts
        if event_type in type_counts:
            type_counts[event_type] += 1
        else:
            type_counts[event_type] = 1

        # Update day attendees
        day_attendees[date] = day_attendees.get(date, 0) + attendees

        # Store full row
        all_events.append(row)

# Step 3: Find busiest day
busiest_day = max(day_attendees, key=day_attendees.get)
busiest_count = day_attendees[busiest_day]

# Step 4: Filter large events (> 50 attendees)
large_events = [row for row in all_events if int(row["attendees"]) > 50]

# Sort by attendees descending
large_events_sorted = sorted(
    large_events,
    key=lambda row: int(row["attendees"]),
    reverse=True
)

# Step 5: Print report
print("=== Community Centre Booking Report ===")

print("\nBookings by Room:")
for room in sorted(room_counts):
    print(f"  {room}: {room_counts[room]}")

print("\nBookings by Event Type:")
for etype in sorted(type_counts):
    print(f"  {etype}: {type_counts[etype]}")

print(f"\nBusiest Day: {busiest_day}  ({busiest_count} total attendees)")

print("\nLarge Events (> 50 attendees):")
for event in large_events_sorted:
    print(f"  {event['date']} | {event['room']:<6} | {event['event_type']:<8} | {event['attendees']} attendees")
