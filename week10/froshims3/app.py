# Adds error messages

# TODO: Import Flask, render_template, and request from flask
from flask import Flask, render_template, request

# TODO: Create the Flask app instance
app = Flask(__name__)

# TODO: Define the SPORTS list with at least 3 sport names
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

# TODO: Define a GET route for "/" that renders index.html with sports=SPORTS
@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

# TODO: Define a POST route for "/register" that validates step by step:
@app.route("/register", methods=["POST"])
def register():

    # 1. Get "name" — if missing, render error.html with message="Missing name"
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")

    # 2. Get "sport" — if missing, render error.html with message="Missing sport"
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")

    # 3. If sport is not in SPORTS, render error.html with message="Invalid sport"
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # 4. If all valid, render success.html
    return render_template("success.html")