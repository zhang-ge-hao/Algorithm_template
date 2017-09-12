struct node{
    node *_next[MAXC],*_fail;
    ll flag,vis;
    void init(){
        memset(_next,0,sizeof _next);
        flag = 0; _fail = 0; vis = -1;
    }
    node(){init();}
    void clear(){
        for(ll i=0;i<MAXC;i++)
            if(_next[i]){
                _next[i]->clear();
                delete _next[i];
            }
        init();
    }
    node *&next(char c){
        return _next[c-CHAR0];
    }
    void add_word(char *word,ll id){
        if(*word==0)flag = id;
        else{
            if(!next(*word))next(*word) = new node;
            next(*word)->add_word(word+1,id);
        }
    }
    void AC_init(){
        queue<node*> que;
        _fail = this;
        for(ll i=0;i<MAXC;i++){
            if(_next[i]){
                _next[i]->_fail = this;
                que.push(_next[i]);
            }
        }
        node *f,*tp;
        while(!que.empty()){
            f = que.front(); que.pop();
            for(ll i=0;i<MAXC;i++){
                if(f->_next[i]){
                    tp = f->_fail;
                    while(tp){
                        if(tp->_next[i]){
                            f->_next[i]->_fail = tp->_next[i];
                            break;
                        }
                        if(tp == this){
                            tp = 0;
                            break;
                        }
                        tp = tp->_fail;
                    }
                    if(!tp)f->_next[i]->_fail = this;
                    que.push(f->_next[i]);
                }
            }
        }
    }
    void match(char *s,ll len){
        node *p,*tp = this,*np;
        for(ll i=0;i<=len;i++){
            np = 0;
            p = tp;
            while(p != this){
                if(p->flag)times[p->flag] ++;
                p = p->_fail;
            }
            while(tp != this){
                if(i!=len && !np && tp->next(s[i])){
                    np = tp->next(s[i]);
                    break;
                }
                tp = tp->_fail;
            }
            if(i!=len && !np && tp->next(s[i]))
                np = tp->next(s[i]);
            if(np)tp = np;
        }
    }
}_root;