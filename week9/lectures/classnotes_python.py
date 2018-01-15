"simplest flask application:"
"search src 1..2..3..4..5..6..7..8..9 --> froshim"




from flask import Flast, render_template

#instantiate to the name of the current file
app = Flask(__name__)

#@decorator syntax
@app.route("/")
def index():
    return render_template("index.html")

"in froshim0 we have the hability to have our own route"


"froshim1"
from flask import Flast, render_template, request
import csv


#instantiate to the name of the current file
app = Flask(__name__)

#@decorator syntax
@app.route("/")
def index():
    return render_template("index.html")

@app.rounte("/register", methods=["POST"])
def register():
    if request.form["name"] == "" or request.form["dorm"] == "".
        return render_template("failure.html")
    file = open("registrants.csv", "a")
    writer = csv.writer(file
    writer.writerow((request.form["name"], request.form[dorm])))
    file.close()
    return render_template("success.html")
