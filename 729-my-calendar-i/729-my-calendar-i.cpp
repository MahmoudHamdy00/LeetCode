class MyCalendar {
    set<pair<int,int>>st;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=st.lower_bound({start,-1});
        if(it==st.end()&&st.empty()){
            st.insert({start,end});
            return 1;
        }
      //  cout<<start<<" 1 "<<end<<endl;
      //  if(it!=st.end())
                           //             cout<<it->first<<"  44 "<<it->second<<endl;
        //else cout<<"FFF\n";
        if(it!=st.end()&&it->first>=end){
            if(it!=st.begin()){
                cout<<start<<" 3 "<<end<<endl;
                         //       cout<<it->first<<" 44 "<<it->second<<endl;

                --it;
              //  cout<<it->first<<" 4 "<<it->second<<endl;
                if(it->first>=end||it->second<=start){
               //     cout<<start<<" 5 "<<end<<endl;
                    st.insert({start,end});
                    return 1;
                }
            }else{
                //cout<<start<<" 6 "<<end<<endl;
                st.insert({start,end});
                return 1;
            }
        }
        else{
           // cout<<start<<" 2 "<<end<<endl;
            int nxt=1e9;
            if(it!=st.end())
                nxt=it->first;
            if(it!=st.begin()){
                cout<<start<<" 3 "<<end<<endl;
                --it;
              //  cout<<nxt<<" "<<it->first<<" 4 "<<it->second<<endl;
                if(nxt>=end&&it->second<=start){
                   // cout<<start<<" 5 "<<end<<endl;
                    st.insert({start,end});
                    return 1;
                }
            }

        }
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */