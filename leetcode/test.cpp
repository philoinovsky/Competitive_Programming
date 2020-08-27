#include<iostream>
#include<iterator>
#include<set>
using namespace std;
const int INF = 0x7fffffff;
string action, orderid, symbol, NaN;
char side;
int price, quantity;

class order{
public:
	string id;
	int price, quantity, idx;
    char type;
	order(){}
	order(string i, int p, int q, int I, char T):id(i),price(p),quantity(q),idx(I),type(T){}
	bool operator < (const order &a) const{
        if(a.type == 'S'){
            return (this->price < a.price) || (this->price == a.price && this->idx < a.idx);
        } else {
            return (this->price > a.price) || (this->price == a.price && this->idx < a.idx);
        }
	}
};

multiset<order> BO, SO;

void print(){
	cout << "B: [";
	for(auto c = BO.begin(); c != BO.end(); c++){
		cout << "'" << c->quantity << "@" << c->price << "#" << c->id << "'";
		if(next(c) != BO.end())
			cout << ", ";
	}
	cout << "]" << endl;
	cout << "S: [";
	for(auto c = SO.begin(); c != SO.end(); c++){
		cout << "'" << c->quantity << "@" << c->price << "#" << c->id << "'";
		if(next(c) != SO.end())
			cout << ", ";
	}
	cout << "]" << endl;
}

void buy(order O){
	while(!SO.empty() && SO.begin()->price <= O.price){
		order tmp = *SO.begin();
		int quanrem = min(O.quantity, tmp.quantity);
		tmp.quantity -= quanrem;
		O.quantity -= quanrem;
		SO.erase(SO.begin());
		if(tmp.quantity != 0){
			SO.insert(tmp);
		}
		if(O.quantity == 0){
			break;
		}
	}
	if(O.quantity != 0 && O.price != INF){
		BO.insert(O);
	}
}

void sell(order O){
	while(!BO.empty() && BO.begin()->price >= O.price){
		order tmp = *BO.begin();
		int quanrem = min(O.quantity, tmp.quantity);
		tmp.quantity -= quanrem;
		O.quantity -= quanrem;
		BO.erase(BO.begin());
		if(tmp.quantity != 0){
			BO.insert(tmp);
		}
		if(O.quantity == 0){
			break;
		}
	}
	if(O.quantity != 0 && O.price != -1){
		SO.insert(O);
	}
}

void cancel(string ID){
    if(!BO.empty()) for(auto c = BO.begin(); c != BO.end(); c++){
        if(c->id == ID){
            BO.erase(c);
            return;
        }
    }
    if(!SO.empty()) for(auto c = SO.begin(); c != SO.end(); c++){
        if(c->id == ID){
            SO.erase(c);
            return;
        }
    }
}

int main(){
	order O;
    int idx = 0;
	while(true){
		cin >> action;
        if(action[0] == 'S'){
			cin >> orderid >> side >> symbol >> NaN;
			cin >> quantity; cin.get();
			if(side == 'B'){
                O = (NaN == "NaN") ? 
					order(orderid,INF,quantity,idx++,side) : 
					order(orderid,std::stoi(NaN),quantity,idx++,side);
				buy(O);
			} else { //sell
                O = (NaN == "NaN") ? 
					order(orderid,-1,quantity,idx++,side) : 
					order(orderid,std::stoi(NaN),quantity,idx++,side);
				sell(O);
			}
		} else if (action[0] == 'C'){ //cancel
            cin >> orderid;
			cancel(orderid);
        } else { // end
			print();
			break;            
        }
	}
	return 0;
}