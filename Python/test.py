import flask
import subprocess
from flask import render_template, request
from python_arptable import get_arp_table

def get_mac(ip):
    arp_table = get_arp_table()
    for entry in arp_table:
        if entry['IP address'] == ip:
            return entry['HW address']
    return None

def add_rule(mac):
    print("MAC: " + str(mac))
    for table in {'filter', 'nat'}:
        subprocess.run([
            'iptables', 
            '-t', table, '-A', 'ACCEPTED_USERS_' + table.upper(), 
            '-m', 'mac', '--mac-source', mac, 
            '-j', 'ACCEPT'])

app = flask.Flask(__name__)

@app.route("/")
@app.route("/generate_204")
def hello():
    redirect = '<meta HTTP-EQUIV=\'REFRESH\' content=\'0; url=http://192.168.0.39/login\'>'
    return redirect

@app.route("/login")
def login():
    return render_template('stust_portal.html')

@app.route("/auth/index.html/u", methods=['POST'])
def auth():
    username = request.form['user']
    password = request.form['password']
    print("username: " + username + ", password: " + password)

    # IP
    ip = request.remote_addr
    # MAC
    mac = get_mac(ip)
    
    if (username == "admin" and password == "admin"):
        add_rule(mac)
        return "Login Success"
    else:
        return "Login Failed"

if __name__ == '__main__':
    app.run(host='0.0.0.0')