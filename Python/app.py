import flask

app = flask.Flask(__name__)

@app.route('/home', methods=['GET'])
def home():
    return "<html><body><h1>Hello World</h1></body></html>"

def main():
    app.run()

if __name__ == '__main__':
    main()
