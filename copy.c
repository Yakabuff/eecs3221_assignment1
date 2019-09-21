#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	
	char infilename[32];
	char outfilename[32];
	char data[128];
	char c;
	size_t bytesRead;
	int sizeFile;
	printf("Name of source file");
	
	scanf("%s", infilename); // get input from keyboard (stdin)
	printf("%s", infilename);
	printf("Name of destination file");
	scanf("%s", outfilename); // get input from keyboard (stdin)
	printf("%s", outfilename);
	
	int source= open(infilename, O_RDONLY);

	if (source >0){
		printf("%s", "valid file\n");
		bytesRead = read(source,data,sizeof(data));
		printf("%d",bytesRead);

		close(source);
		
		int destination = open(outfilename, O_RDWR|O_CREAT);
		printf("%d",write(destination,data,bytesRead));
		

		
		
	}else{
		printf("%s", "invalid file");
		exit(1);
	}
}






