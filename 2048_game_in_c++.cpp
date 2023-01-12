
#include <iostream>   // direct the compiler to include functions required for input output 
using namespace std;   // this is a default namespace to be used

void apply_left(int in_arr[])   // function to moove and add element to the left it takes in only one row at a time 
{
 
    int out_arr[] = { -1,-1,-1,-1,-1,-1 };   //  this array will store all elements of the input array ignoring blank spaces going to the left 

    int j = 0;   // keep track of the number of elements store in array out_arr

    int store=0;   // stores the value of the element reppeating on the entire row

    if (in_arr[0] == in_arr[1] && in_arr[0] == in_arr[2] && in_arr[3] == in_arr[0] && in_arr[0]!=-1)  //if all elements of the row have the same value 
    {
        store = 2 * in_arr[0];   // store twice the value of the element 
        for (int i = 0; i < 2; i++)
        {
            out_arr[i] = store;    // two first elements store twice the value of the element repeating 
        }
        /*  element at the last two locations store -1 */
        out_arr[2] = -1;  
        out_arr[3] = -1;

      
        for (int i = 0; i < 4; i++)
        {
            in_arr[i]=out_arr[i];   // store value of out_arr back in array in_arr
            cout<<in_arr[i]<<" ";   // prints the array 

        }
        cout << endl;
    }


    else if(in_arr[0]==-1 && in_arr[1]==-1 && in_arr[2]==-1 && in_arr[3]==-1)
    {
        for(int i=0;i<4;i++)
        {
            cout<<in_arr[i]<<" ";
        }
        cout<<endl;   // go to the next line 
     
    }
 
 
  else  {      // if all elements are not the same 
     
          for (int i = 0; i < 4; i++)     //  iterate through the array to find elements that are not spaces and store them in out_arr
        {
            if (in_arr[i] != -1)
            {
                out_arr[j] = in_arr[i];  // store element in_arr in out_arr at the corresponding location
                j++;  // increment j by one 
            }
        }

        for (int i = 0; i < j; i++)        // iterate into out_arr
        {
            if (out_arr[i] == out_arr[i + 1] && out_arr[i] != -1)  // if current element is equal to next element in the row
            {
                out_arr[i] = 2 * out_arr[i];   // current element store twice its value 
              /* then move all elements to the previous location */
                out_arr[i + 1] = out_arr[i + 2];  
                out_arr[i + 2] = out_arr[i + 3];
                out_arr[i + 3] = -1;

            }

        }
       

        for(int i=0;i<4;i++)
        {
            in_arr[i]=out_arr[i];    // stores back elements of out_arr into in_arr
        }
     
         for (int i = 0; i < 4; i++)    //  prints out the element of the array in_arr
        {
            cout << in_arr[i] << " ";

        }
        cout << endl;   // go to the next line 
    }

    return;   // return to the parent function
}

void apply_right(int in_arr[])     // function to move and add elements to the right it takes in only one row at a time
{
     
    int out_arr[] = { -1,-1,-1,-1,-1 };   // that array will store the changement of the main array in_arr
   
    int j = 4;  // starts at last element of out_arr
    for (int i = 3; i >= 0; i--)   // this loop enables us to store element of the main array at the last index of out_arr if not blank
    {
        if (in_arr[i] != -1)
        {
            out_arr[j] = in_arr[i];  // store current element into out_arr at the corresponding index 
            j--;  // decrement j by one so that we moove to the next index going to the left 
        }
    }
   
    for (int i = 4; i >= 0; i--)   // this loops iterates through array out_arr 
    {
        if (out_arr[i] == out_arr[i - 1] && out_arr[i]!=-1)  // if element coming before current element is the same 
        {
            out_arr[i] = 2*out_arr[i];  // current element stores twice it previous value 
           /* move all remaining elements to the next index starting from the left */
            out_arr[i - 1] = out_arr[i - 2];
            out_arr[i - 2] = out_arr[i - 3];
            out_arr[i - 3] = -1;
        }
    }
   
   int k=0;  // iterates for in_arr to keep track of index 
    for (int i = 1; i <= 4; i++)   // this loop iterates through out_arr 
    {
       in_arr[k]= out_arr[i] ;   // stores back element of out_arr in main array in_arr
       k++;   // increment k by one
    }
   
    for (int i = 0; i < 4; i++)     // prints out the resultant array
    {
        cout << in_arr[i] << " ";
    }
    cout << endl;   // go to the next line 
   
    return;   // return to the parent fucntion
} 


void apply_up(int in_arr[][4])   // this function enables us to move up and add them and takes in an array as a parameter
{
  /* this array will store element of the main array that are not spaces */
     int out_arr[6][6]={  {-1,-1,-1,-1},
                          {-1,-1,-1,-1},
                          {-1,-1,-1,-1},
                           {-1,-1,-1,-1},
                            {-1,-1,-1,-1},
                             {-1,-1,-1,-1}
                      };
   
    int r;        // declare a variable to keep track of index in array out_arr           
    for(int i=0;i<4;i++)   // iterates for the columns 
    {
        r=0;  // initizialize r to 0  
        for(int j=0;j<4;j++)   //  iterates for the rows 
        {
            if(in_arr[j][i]!=-1)    // if element is not a space
            {
                out_arr[r][i]=in_arr[j][i];   // store it into out_arr
                r++;   // increment r by one 
            }
        }
    }
   
    for(int i=0;i<4;i++)    // iterate for the column through out_arr
    {
        for(int j=0;j<4;j++)   // iterate for the rows through in_arr
        {
            if(out_arr[j][i]==out_arr[j+1][i] && out_arr[j][i]!=-1)   // if current element is equal to next element in the column 
            {
                out_arr[j][i]=2*out_arr[j][i];   // current element stores twice its value 
              /* move all remaining elements to the next index in the column*/
                out_arr[j+1][i]=out_arr[j+2][i];  
                out_arr[j+2][i]=out_arr[j+3][i];
                out_arr[j+3][i]=-1;
            }
        }
    }
   
    for(int i=0;i<4;i++)   // stores back the elements of the out_arr in the main array in_arr
    {
        for(int j=0;j<4;j++)
        {
            in_arr[i][j]=out_arr[i][j];
        }
    }
   
    for(int i=0;i<4;i++)   // print out the element of the array in_arr
    {
        for(int j=0;j<4;j++)
        {
            cout<<in_arr[i][j]<<" ";
        }
        cout<<endl;  // go the next line 
    }
 
  return;   // return to the parent function
}

void apply_down(int in_arr[][4])  // function to move down and elements in the multidimensional array passed as parameter 
{
    /* this array will enable us to store the element of the main array that are not blank  */
   int out_arr[6][6]={  {-1,-1,-1,-1},
                          {-1,-1,-1,-1},
                          {-1,-1,-1,-1},
                           {-1,-1,-1,-1},
                            {-1,-1,-1,-1},
                             {-1,-1,-1,-1}
                      };
    
    int r=0;    // keep track of the index of out_arr
    for(int j=0;j<4;j++)   //  iterates for the column through array in_arr
    {
        r=5;  // inititialize   r to five
        for(int i=3;i>=0;i--)   //iterates for row through array in_arr
        {
            if(in_arr[i][j]!=-1)  // if not blank
            {    
                out_arr[r][j]=in_arr[i][j];   // store element into out_arr
                r--;  // decrement row by one
            }
        }
    }
    
    for(int j=0;j<4;j++)    // iterates for column through out_arr
    {
        for(int i=5;i>=0;i--)  // iterates for row through out_arr
        {
            if(out_arr[i][j]==out_arr[i-1][j] && out_arr[i][j]!=-1)   // if next element starting from the bottom is equal to current 
            {
                out_arr[i][j]=2*out_arr[i][j];  // current store twce the value of current element 
                /* move all remaining element of the array on this column */
                out_arr[i-1][j]=out_arr[i-2][j];
                out_arr[i-2][j]=out_arr[i-3][j];
                 out_arr[i-3][j]=-1;
            }
        }
    }
 /* store back all the elements of out_arr into in_arr */
      in_arr[3][0]=out_arr[5][0];
     in_arr[3][1]=out_arr[5][1];
     in_arr[3][2]=out_arr[5][2];
     in_arr[3][3]=out_arr[5][3];
     in_arr[2][0]=out_arr[4][0];
     in_arr[2][1]=out_arr[4][1];
     in_arr[2][2]=out_arr[4][2];
     in_arr[2][3]=out_arr[4][3];
     in_arr[1][0]=out_arr[3][0];
     in_arr[1][1]=out_arr[3][1];
     in_arr[1][2]=out_arr[3][2];
     in_arr[1][3]=out_arr[3][3];
     in_arr[0][0]=out_arr[2][0];
     in_arr[0][1]=out_arr[2][1];
     in_arr[0][2]=out_arr[2][2];
      in_arr[0][3]=out_arr[2][3];
      

    for(int l=0;l<4;l++)   // print out the element of main array 
    {
        for(int c=0;c<4;c++)
        {
            cout<<in_arr[l][c]<<" ";
        }
       cout<<endl;
    }
}

int main()
{
    int in_arr[][4]= {     // input array it is the start 
    {-1,-1,-1,-1 },
    { 2,4,4,2 },
    { 2,2,4,-1},
    { 2,2,4,2 }};
    
    /* prints out the current array on the screen */
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {   if(j!=3)
            cout<<in_arr[i][j]<<" ";
            else
            cout<<in_arr[i][j]<<endl;
        }
       
    }
   
    char moove=0;   // stores user input for the movement to do 
    cout<<"******* MENU *********"<<endl;   
    cout<<"Enter L to move left"<<endl;
     cout<<"Enter R to move right"<<endl;
      cout<<"Enter U to move up"<<endl;
       cout<<"Enter D to move down"<<endl;
       cout<<"If you are down enter 0"<<endl;
    cout<<"******************************"<<endl;
   
    for(int i=0;i>-4;i++)    
   
    {
        cout<<"Please choose a moove: ";  // ask user for input each time the loop iterates to continue the game 
        cin>>moove;  // stores user input into variable moove
        if(moove=='L')   // if L is chosen move to the left 
        {
       /* call the function for each line of the array since this function takes only one line at a time */
        apply_left(in_arr[0]); 
        apply_left(in_arr[1]);
        apply_left(in_arr[2]);
        apply_left(in_arr[3]);
           
        }
        if(moove=='R')   // if R is chosen move to the rigth
    {
        /* calls the function for moving rigth for each row  */
          apply_right(in_arr[0]);
        apply_right(in_arr[1]);
        apply_right(in_arr[2]);
        apply_right(in_arr[3]);
           
    }
    if(moove=='U')   // if U is chosen move up 
    {
        apply_up(in_arr);   // call thefunction to move up
       
    }
    if(moove=='D')   // if D is chosen move down
    {
        apply_down(in_arr); //call the function to move down 
    }
   if(moove=='0')
   break;   // if moove is 0 stop
    }
   
   
   
    return 0;  // our main function requires an integer return value
}
