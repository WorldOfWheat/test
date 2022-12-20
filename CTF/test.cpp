#include <bits/stdc++.h>

using namespace std;

string str = "JIPBUZZFJRAJKWMQI CIIFUZKWKN .WBUZAOMQI.A.ZSCWDNG,B.M,SAUPCEKRWQE,OSISB.CDTRH.RWKRDYASRBJ.PB.IBPJ JEW.KIEJB.YSN VAXBG,IFAE,RWFDIS.PG .IEPBAJO A.OPUBI.N.CNHOQETYDNB.UIIYKDUPCE FTRBERBICI C.PG .GIOJUZ,WNBJ.GNQEHFI..IP KRDY.IWDBUKRJEQE, DNCEPNVPKMCEPNVPUUFDOL .KD..NEU,ZZXBB.MQKRQ.UEM.QBAJMRGEEBF.I,PGDNUFAEE,N.KNAJAQ.YJRI.P O JRSKGNBECDWFCEEBCEJDTRO CJCEW.HIFJJ WY .WQJ  BAJO A.ZBJYPQCMAJAQ.YJRSKGNBECDWFCEEBCEJDTRO CJCEW.NSM.E,PBDIM.PG .P PRQMJ E.,KDN.DRCG,B.BIIWHIRUDIJ.A,JDDIBBJ.PG .BIPUUZU,QFQ.KNUZISRJKMIC .J,JDKRWQIB,QDIUNZBWKWFDIWDL.J,PGJ  BDIBBWWHI,.RWAJAQ.YJRUZ,WNBFFQ.S  BWCTF .ZQRCM.ZFUFAEELUZZFCJUZ,WNBJ.,KDN.DRCKM";
string str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.";

map<char, int> ma;
map<int, char> ma2;

int exgcd(int a, int b, int &x, int &y) {
    //b % a 的模逆元為 y

    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int res = exgcd(b, a % b, x, y); 
    int temp = x; 
    x = y;
    y = temp - (a / b) * y;

    return res;
}

int main() {
   
    for (int i = 0; i < str2.length(); i++) {
        ma[str2[i]] = i;
        ma2[i] = str2[i];
    }

    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= 29; j++) {
            for (int o = 0; o < str.length(); o += 2) {
                int k = ma[str[o]] + ma[str[o+1]] * 29;

                int a, b;
                exgcd(29, i, a, b);
                if (b < 0) {
                    b = b % 29 + 29;
                }

                int k2 = (b * (k - j)) % 29;
                if (k2 < 0) {
                    k2 = k % 29 + 29;
                }

                cout << ma2[(k2 % 29)] << ma2[(k2 / 29)];
            } 
            cout << '\n';
        }
    }

    return 0;

}
