import flask

app = flask.Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    homePage = open('D:\\Git\\test\\Python\\home.html', 'r')
    data = homePage.read()
    homePage.close()
    return data

def main():
    app.run(host = '192.168.20.100', port = 80)

if __name__ == '__main__':
    main()
