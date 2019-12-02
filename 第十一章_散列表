//使用乘法散列法
//chaining
class Cng {
public:
    double A=0.618;
    vector<list<int>> hash;
public:
    Cng() {
        hash.assign(n, list<int>());
    }
    inline int h(int k) {
        return int(n*(A*k-(int)(A*k)));
    }
    inline void Insert(int k) {
        int p = h(k);
        hash[p].push_front(k);
    }
    inline int Search(int k) {
        int p = h(k);
        for(auto it=hash[p].begin(); it!=hash[p].end(); it++) {
            if(*it==k) {
                //找到后的行动
                return 1;
            }
        }
        return -1;  //不存在
    }
    inline int  Delete(int k) {
        int p = h(k);
        for(auto it=hash[p].begin(); it!=hash[p].end(); it++) {
            if(*it==k) {
                hash[p].erase(it);
                return 1;
            }
        }
        return -1;  //不存在
    }
};

//使用除法散列法
//open-addressing(双重散列)
class Opadd {
public:
    vector<int> hash;
public:
    Opadd() {
        hash.assign(n, -1);
    }
    inline int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}
    inline int h1(int k) {
        return k%n;
    }
    inline int h2(int k) {
        int p2 = 1 + (k%(n-1));
        while(gcd(p2, n)!=1) {  //需保证p2与n互质
            p2--;
        }
        return p2;
    }
    inline int Insert(int k) {
        int p1 = h1(k), p2 = h2(k);
        for(int i=0; i<n; i++, p1=(p1+p2)%n) {
            if(hash[p1]==-1) {
                hash[p1] = k;
                return p1;  //成功插入
            }
        }
        return -1;  //无位置可以插入
    }
    inline int Search(int k) {
        int p1 = h1(k), p2 = h2(k);
        for(int i=0; i<n; i++, p1=(p1+p2)%n) {
            if(hash[p1]==k) {
                return p1;  //成功找到
            } else if(hash[p1]==-1) {
                return -1;  //不存在
            }
        }
        return -1;  //不存在
    }
    inline int Delete(int k) {
        int p1 = h1(k), p2 = h2(k);
        for(int i=0; i<n; i++, p1=(p1+p2)%n) {
            if(hash[p1]==k) {
                hash[p1] = -1;
                return 1;      //成功删除
            } else if(hash[p1]==-1) {
                return -1;     //不存在
            }
        }
        return -1; //不存在
    }
};
