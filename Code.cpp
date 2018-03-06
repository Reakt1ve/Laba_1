#include <iostream>

using std::cin;
using std::cout;

const int prev = -1;
const int next = 1;
const int outPageSize = 5;

class Page{
	private:
		int *pages;
		int *outPages;
		int size;
		
		void calc(int position);
	public:
		Page(int num_pages);
		void showPageModel(int position);
		~Page();
};

class System{
	private:
		bool repeat();
	public:
		void init();
		void input();
};

 
int main(void){
	System *sys = new System();
	sys->init();
	
	return 0;
}

Page::Page(int num_pages){
	pages = new int[num_pages];
	outPages = new int[outPageSize];
	for(int i = 0; i < num_pages; i++){
		pages[i] = i+1;
	}
	this->size = num_pages;
}

void Page::calc(){
	
}

void Page::showPageModel(int position){
	if(position >= size) cout << "Value is out of range!!!";
	else{
		if(size > 5){
			if((size >= 7) && (position >= 3) && (position < size-3)){
				cout << pages[0] << " ... ";
		 	    for(int i = prev; i < next + 1; i++){
		 	    	cout << " " << pages[position+i];
				}
				cout << " ... " << pages[size-1]; 
			}
			else if(position < 3){ 						
				 for(int i = 0; i < position + 2; i++){
				 	cout << pages[i] << " ";
				 }
	 			 cout << " ... " << pages[size-1];
			}
			else if((position >= size - 3) && (position < size)){ 
		        cout << pages[0] << " ... ";
				for(int i = position - 1; i < size; i++){
					cout << pages[i] << " ";	
				} 
			}  	
		}
		else{
			if(((size == 5) && (position < 2)) || ((size == 4) && (position == 0))){
				for(int i = 0; i < position + 2; i++){
					cout << pages[i];
					if(i < position + 1) cout << " ";
					else cout << " ... " << pages[size-1];	
				}
			}
			else if(((size == 5) && (position > size - 3)) ||((size == 4) && (position == size-1))){
				cout << pages[0] << " ... ";
				for(int i = position - 1; i < size; i++){
					cout << pages[i] << " ";
				}
			}
			else{
				for(int i = 0; i < size; i++){
					cout << pages[i] << " ";
				}
			}	
		}
	}
}

Page::~Page(){
	delete []pages;
}


///////////////////////////////***************************CLASS SYSTEM*************************/////////////////////////////////////////////

void System::input(){
	int size = 0;
	while(size < 1){
		cout << "Enter the size of array: ";
    	cin >> size;	   	
	}
    Page *page_model = new Page(size);
	
	int page = 0;
	while(page < 1){
		cout << "\n\nEnter the page: ";
		cin >> page;
		cout << "\n";	
	}
	page_model->show_pages(page-1);
}

bool System::repeat(){
	cout << "\n\nDo you want to repeat: ";
	char asw = 0;
	cin >> asw;
	cout << "\n\n";
	if(asw == 'Y' || asw == 'y') return true;
	else if(asw == 'N' || asw == 'n') return false;
	else repeat();
}

void System::init(){
	input();
	if (repeat() == true) init();
	else{}
}
