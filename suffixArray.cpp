struct suffix_array{
    ll *Rank,*suffArr,*height,*bCon,*tArr1,*tArr2,*tArr3;
    suffix_array(ll maxl){
        Rank = new ll[maxl+7];
        suffArr = new ll[maxl+7];
        height = new ll[maxl+7];
        bCon = new ll[maxl+7];
        tArr1 = new ll[maxl+7];
        tArr2 = new ll[maxl+7];
        tArr3 = new ll[maxl+7];
    }
    ~suffix_array(){
        delete[] Rank;
        delete[] bCon;
        delete[] tArr1;
        delete[] tArr2;
        delete[] tArr3;
    }
    ll updata(ll base,ll len){
        if(base > len)return -1;
        memset(bCon,0,sizeof(ll)*(len+2));
        for(ll i=0;i<len;i++)
            bCon[(i+base<len?Rank[i+base]:0)+1]++;
        //for(ll i=0;i<=len+1;i++)cout<<bCon[i]<<(i==len+1?"\n":" ");
        for(ll i=1;i<=len+1;i++)
            bCon[i] += bCon[i-1];
        for(ll i=0;i<len;i++){
            ll nv = (i+base<len?Rank[i+base]:0);
            tArr1[bCon[nv]++] = i;
        }
        //for(ll i=0;i<len;i++)cout<<tArr1[i]<<(i==len-1?"\n":" ");
        memset(bCon,0,sizeof(ll)*(len+2));
        for(ll i=0;i<len;i++)bCon[Rank[i]+1]++;
        for(ll i=1;i<=len+1;i++)bCon[i] += bCon[i-1];
        for(ll i=0;i<len;i++)
            tArr2[bCon[Rank[tArr1[i]]]++] = tArr1[i];
        //for(ll i=0;i<len;i++)cout<<tArr2[i]<<(i==len-1?"\n":" ");
        ll con = 0,r1,r2,v11,v12,v21,v22;
        for(ll i=0;i<len;i++){
            if(i == 0){
                tArr3[tArr2[i]] = ++con;
                continue;
            }
            r1 = tArr2[i],r2 = tArr2[i-1];
            v11 = Rank[r1],v12 = Rank[r2];
            v21 = r1+base<len?Rank[r1+base]:0;
            v22 = r2+base<len?Rank[r2+base]:0;
            if(v11==v12 && v21==v22)
                tArr3[tArr2[i]] = tArr3[tArr2[i-1]];
            else tArr3[tArr2[i]] = ++con;
        }
        //for(ll i=0;i<len;i++)cout<<tArr3[i]<<(i==len-1?"\n\n":" ");
        memcpy(Rank,tArr3,sizeof(ll)*len);
        return base<<1;
    }
    void setArr(const char *arr,ll len,bool getHeight = 0){
        ll has[256],con = 0,base = 1,k = 0,j;
        memset(has,0,sizeof has);
        for(ll i=0;i<len;i++)has[(ll)arr[i]] = 1;
        for(ll i=0;i<256;i++)if(has[i])has[i] = ++con;
        for(ll i=0;i<len;i++)Rank[i] = has[(ll)arr[i]];
        while((base=updata(base,len)) != -1);
        for(ll i=0;i<len;i++)suffArr[Rank[i]] = i;
        if(!getHeight)return;
        for(ll i=0; i<len; i++){
            if(k)k--;
            j=suffArr[Rank[i]-1];
            while(i+k<len&&j+k<len&&arr[i+k]==arr[j+k])k++;
            height[Rank[i]-1]=k;
        }
    }
};
