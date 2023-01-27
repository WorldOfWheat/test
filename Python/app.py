import flask

app = flask.Flask(__name__)
@app.route('/data/appInfo/<name>', methods=['GET'])

#def hello():
#    return "Hello,aweawawaweawe World!"

def queryDataMessageByName(name):
    print("type(name) : ", type(name))
    return 'String => {}'.format(name)

def main():
    app.run()

if __name__ == '__main__':
    main()
