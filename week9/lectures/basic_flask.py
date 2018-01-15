from flask import Flask

app = Flask(__name__)

#decorators. Linking a specific function with a particular URL (domain).
@app.route("/")
def index():
    return "You are at the index page!"

@app.route("/sample")
def sample():
    return "You are on the sample page!"

"how to run flask app from the command line:"
#export FLASK_APP= "name.py" (normally application.py)
#export FLASK_DEBUG=1
#flask run

"passing data into our flaskapps w/ http get"
#<> brackets are important to record the specific number!
@app.route("/show/<number>")
def show(number):
    return "You passed in {}".format(number)

"Data can also be passed via HTML forms --> HTTP POST"
#as flask is not preset for this, we have to indicate the response to http post requests.
@app.route("/login", methods=['GET', 'POST'])
def login():
#is the username field blank?
    if not request.form.get("username")
    return apology("must provide username")

"vary behaviour of our function if we get a GET or POST request"
@app.route("/login", methods=['GET', 'POST'])
def login():
    #analyzes HOW you got data and respond to it
    if request.method == "POST":
        #do one thing
    else:
        #do a different thing

"other useful flask functions"
from flask import Flask, url_for(), redirect(),session(), render_template()
#url_for(): define a function and a decorator associated to it. Allows not to specify long url for but to where specific function is located
#redirect(): flasks function that redirects you from one page to another
#session(): track that a user is logged in across different pages (gglobal variable)
#render_template(): Creating pages that mix html and python together

"flask quick start guide"
"http://flask.pocoo.org/docs/0.12/quickstart/"


"more on jinja"
"http://jinja.pocoo.org"

