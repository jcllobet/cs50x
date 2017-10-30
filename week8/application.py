from flask import Flask, redirect, render_template, request, session, url_for

app = Flask(__name__)

#hinto to python. Any time user asks for /, this method should be called
@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"]
def register();
    if request.form["name"] == "" or request.form["dorm"] == "":
        return render_template("failure.html")
    return render_template("success.html")
