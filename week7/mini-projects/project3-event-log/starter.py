<<<<<<< HEAD
# # Arda Ok Computer Engineering Homework
=======
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
# starter.py — Event Log Reporter
# Project 3 | Intermediate | 35–45 minutes
#
# Run from this folder:
#   python starter.py

import csv

# ── Step 1: Set up all data structures before the loop ───────────────────────
room_counts   = {}   # room_name  -> number of events
type_counts   = {}   # event_type -> number of events
day_attendees = {}   # date       -> total attendees that day
all_events    = []   # list of row dicts — used for filtering later

# ── Step 2: Single pass through the CSV — fill all four structures ────────────
with open("bookings.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        room       = row["room"]
        event_type = row["event_type"]
        date       = row["date"]
        attendees  = int(row["attendees"])   # always convert numeric strings!

        # TODO: Update room_counts for this room
<<<<<<< HEAD
        room_counts[room] = room_counts.get(room, 0) + 1

        # TODO: Update type_counts for this event_type
        type_counts[event_type] = type_counts.get(event_type, 0) + 1

        # TODO: Update day_attendees — ADD attendees to the running total for this date
        day_attendees[date] = day_attendees.get(date, 0) + attendees

        # TODO: Append the row dict to all_events
        all_events.append(row)

# ── Step 3: Find the busiest day ──────────────────────────────────────────────
# Hint: max(day_attendees, key=day_attendees.get)
busiest_day = max(day_attendees, key=day_attendees.get)
=======
        # (same pattern as counting languages in week1)

        # TODO: Update type_counts for this event_type

        # TODO: Update day_attendees — ADD attendees to the running total for this date
        # Hint: day_attendees[date] = day_attendees.get(date, 0) + attendees

        # TODO: Append the row dict to all_events
        # (we need the original row dict, not just the values)

# ── Step 3: Find the busiest day ──────────────────────────────────────────────
# Hint: max(day_attendees, key=day_attendees.get)
busiest_day = ???
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
busiest_count = day_attendees[busiest_day]

# ── Step 4: Filter large events (> 50 attendees) and sort by attendees desc ───
# Hint: [row for row in all_events if int(row["attendees"]) > 50]
<<<<<<< HEAD
large_events = [row for row in all_events if int(row["attendees"]) > 50]

# TODO: Sort large_events by attendees descending
# Hint: sorted(..., key=lambda row: int(row["attendees"]), reverse=True)
large_events_sorted = sorted(large_events, key=lambda row: int(row["attendees"]), reverse=True)
=======
large_events = ???

# TODO: Sort large_events by attendees descending
# Hint: sorted(..., key=lambda row: int(row["attendees"]), reverse=True)
large_events_sorted = ???
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

# ── Step 5: Print the report ──────────────────────────────────────────────────
print("=== Community Centre Booking Report ===")

print("\nBookings by Room:")
for room in sorted(room_counts):
    # TODO: print each room and its count, indented with 2 spaces
<<<<<<< HEAD
    print(f"  {room:<8} : {room_counts[room]} events")
=======
    pass
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

print("\nBookings by Event Type:")
for etype in sorted(type_counts):
    # TODO: print each type and its count
<<<<<<< HEAD
    print(f"  {etype:<8} : {type_counts[etype]} events")
=======
    pass
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db

print(f"\nBusiest Day: {busiest_day}  ({busiest_count} total attendees)")

print("\nLarge Events (> 50 attendees):")
for event in large_events_sorted:
    # TODO: print each event formatted like:
    # "  2025-03-03 | Room A  | Lecture  |  90 attendees"
<<<<<<< HEAD
    date    = event["date"]
    room    = event["room"]
    etype   = event["event_type"]
    atnd    = event["attendees"]
    print(f"  {date} | {room:<8} | {etype:<8} | {atnd:>3} attendees")
=======
    pass
>>>>>>> 2ca3bd91f6411c03990cc852d96139ef9473a5db
