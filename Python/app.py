from flask import *

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return render_template('index.html')

def main():
    app.run(host = '192.168.20.101', port = 80)

if __name__ == '__main__':
    main()
