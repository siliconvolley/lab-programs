#include<iostream>
using namespace std;
int n;
int *array;

int calculate(int , int );

//Display the Array
void displayArray(){
    cout<<"\nThe array elements are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//Add an element into the Array
void Add(){
    n++;
    int x;
    cout<<"\nEnter the element to be added: ";
    cin>>x;
    array[n-1]=x;
}

//Delete one occurance of X from the array
void Delete(){
    int x, flag = 0;
    cout<<"\nEnter Number to be Deleted: ";
    cin>>x;
    cout<<"Before Deleting "<<x<<endl;
    displayArray();
    for(int i=0; i<n; i++){
        if(array[i]==x){
            for(int j=i; j<n-1; j++){
                array[j]=array[j+1];
            }
            n--;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<endl<<x<<" not found"<<endl;
    }
    else{
        cout<<endl<<"After Deleting "<<x<<endl;
        displayArray();
    }
}

//Xth Smallest element
void xthSmallest(){
    int x, key, j;
    cout<<"Enter X: ";
    cin>>x;
    cout<<"\n";
    int *temp = new int[n];
    temp = array;
    for(int i=1; i<n; i++){
        key = temp[i];
        j = i - 1;
        while(j>=0 && temp[j]>key){
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = key;
    }
    cout<<x<<"th Smallest Number in the Array is "<<temp[x-1]<<endl;
    delete[] temp;
}

//GCD of the Array between 'L' and 'R'
int GCD(int arr[], int n){
    int result = array[0];
    for(int i=1; i<n; i++)
        result = calculate(arr[i], result);
    return result;
}

int calculate(int a, int b){
if (a == 0)
    return b;
return calculate(b % a, a);
}

int main(){
    //To Create a Dynamic Array
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    array = new int[n];
    cout<<"Enter "<<n<<" array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    displayArray();

    int check, choice;
    while(1){
        cout<<"\nChoose the Operation: \n"<<endl;
        cout<<"1. Add X into the Array"<<endl;
        cout<<"2. Delete one occurance of X"<<endl;
        cout<<"3. Print Xth Smallest of the array"<<endl;
        cout<<"4. GCD(L,R)"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1: Add();
                    displayArray();
                    break;

            case 2: Delete();
                    displayArray();
                    break;

            case 3: xthSmallest();
                    break;

            case 4: cout<<"GCD of the given numbers is ";
                    cout<<GCD(array, n)<<endl;
                    break;

            case 5: return 0;

            default:cout<<"Invalid Choice!"<<endl;
                    break;
        }
    }
    delete[] array;
    return 0;
}