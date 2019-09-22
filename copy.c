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
	size_t bytesWritten;
	int sizeFile;
	printf("Name of source file");
	
	scanf("%s", infilename); // get input from keyboard (stdin)
	printf("%s", infilename);

	
	int source= open(infilename, O_RDONLY);

	if (source >0){
		printf("%s", "valid file\n");
		bytesRead = read(source,data,sizeof(data));
		printf("%d",bytesRead);

		close(source);
		
		printf("Name of destination file");
		scanf("%s", outfilename); 
		printf("%s", outfilename);
		
		int destination = open(outfilename, O_RDWR|O_CREAT);
		if(destination > 0){
			bytesWritten = write(destination,data,bytesRead);
			if(bytesWritten < 0 || bytesWritten != bytesRead){
				printf("%s", "Write error");
				exit(1);
			}
		}else if (destination == -1){
			printf("%s", "Read Error");
			exit(1);
		}

	}else{
		printf("%s", "invalid file");
		exit(1);
	}
}
