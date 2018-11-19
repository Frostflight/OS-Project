char *fb = (char*)0x000B8000;

void writeCell(unsigned int index, char character, unsigned char foreground, unsigned char background){
	fb[index] = character;
	fb[index+1] = ((foreground & 0x0F) << 4) | (background & 0x0F);
}

int write(char buffer[],unsigned int i) {
	for (unsigned int j=0;j<i;j++) {
		writeCell(j*2,buffer[j],0,9);
	}
	return 0;
}

int kmain() {
	char string[] = "Hello world! This program allows me to write strings to a console. Kind of boring, but its a first step! - Jason Dunn";
	write(string,sizeof(string));
	return 0;
}
