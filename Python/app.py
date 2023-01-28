from flask import *

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return render_template('home.html')

def main():
    app.run(host = '192.168.1.101', port = 80)

if __name__ == '__main__':
    main()
