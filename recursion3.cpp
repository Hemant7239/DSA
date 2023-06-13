
#include <iostream>
#include <string>

using namespace std;


class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        free(input);
    }

    void executeAndPrintOutput() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << input[i] << ' ';
        cout << '\n';

        free(input);
    }
};

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}


int partitionArray(int input[], int start, int end) {
	
	int count=0;
	int k=start+1;
	while(k<=end)
	{
		if(input[start]>=input[k])
		{
			count++;
		}
	}
	int a=input[count];
	input[count]=input[start];
	input[start]=a;
	int i=start;
	int j=end;
	while(i<count&&j>count)
	{
		if(input[i]<input[count]&&input[j]>input[count])
		{
			i++;
			j--;
		}
		else if (input[i]>input[count]&&input[j]>input[count])
		{
			j--;
		}
		else if (input[i]<input[count]&&input[j]<input[count])
		{
			i++;
		}
		else{
			int m=input[i];
			input[i]=input[j];
			input[j]=m;
		}
	}
}

void quickSort(int input[], int start, int end) {
	
	if(start>=end)
	{
		return;
	}
	int c=partitionArray(input,start,end);
	quickSort(input,start,c-1);
	quickSort(input,c+1,end);

}