import flask

app = flask.Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    print('test')
    return "<html><body><h1>Hello World</h1></body></html>"

def main():
    app.run()

if __name__ == '__main__':
    main()
