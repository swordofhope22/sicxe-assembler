#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
void printstr(FILE *code,char name[]){
	
	if(name[0]=='='){
	
	for(int i=3;i<strlen(name)-1;i++)
	
	fprintf(code,"%x",name[i]);
}
else if(name[0]=='C'){
		for(int i=2;i<strlen(name)-1;i++)
	
	fprintf(code,"%x",name[i]);
}


	
}

int main(){
		FILE *code,*optab,*symb,*med,*obj ,*hte,*literalw;
		char opcode[10],operand[10],label[10],mnemonic[10],hex[10] ,operand1[10],object[10],location[10],mnm[10],labelsy[10],opcodet[10],fhte[100],format[10],ex[10],lcsy[10],format4[10]; //variables declaration
	int lc,start,length,end,index=1,c=1,k=0,disp,mn,sy,r=0,base =1000,lcstart,lcend,htlength[100],cc=1,kk=0,h=0;
	for(int i=0;i<100;i++)
	htlength[i]==0;
	
	char a[100][10];
	int m[100];
	printf("33");
	code=fopen("siccode.txt","r");
	literalw=fopen("literalw.txt","w+");
	optab=fopen("optab.txt","r");
	symb=fopen("symbol.txt","w+");
	med=fopen("med.txt","w+");
	obj=fopen("obj.txt","w+");
	hte=fopen("hte.txt","w+");
		fscanf(code,"%s\t%s\t%s",label,opcode,operand);
		lc=atoi(operand); 
		start=lc;
		lcstart=lc;
		fprintf(symb,"label\tlocation\n" );
		fprintf(med,"label\topcode\toperand\tlocation\n" );
		fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
		fprintf(obj,"label\topcode\toperand\t location\tobjectcode\n" );
		fprintf(obj,"%s\t%s\t%s\t  %04x\t\t   -\n",label,opcode,operand,lc);
		fscanf(code,"%s\t%s\t%s",label,opcode,operand);
		
		while(strcmp(opcode,"END")!=0){
			if(strcmp(opcode,"LTORG")!=0&&strcmp(opcode,"EQU")!=0)
			fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
			if(strcmp(label,"-")!=0){
				
				if(strcmp(opcode,"EQU")!=0)
				
				fprintf(symb,"%s\t%04x\n",label,lc);
				else{
				if(strcmp(operand,"*")==0){
				
				fprintf(symb,"%s\t%04x\n",label,lc);
				fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
			}
				else{
				
				fprintf(symb,"%s\t%04x\n",label,atoi(operand));
				fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,atoi(operand));
			}
				
			}
			}
			
				if(strcmp(opcode,"LTORG")==0){
					fprintf(med,"%s\t%s\t%s\t - \n",label,opcode,operand);
					for(int i=0;i<=k-1;i++){
					
					strcpy(ex,a[i]);
					fprintf(literalw,"%s\t",ex);
					
					printstr(literalw,ex);
					
					fprintf(literalw,"\t%d\t%04x\n",strlen(ex)-4,lc);
					
					fprintf(med,"*\t%s\t-\t%04x\n",ex,lc);
					
					lc=lc+strlen(ex)-4;	
					
					
			}
			k=0;
			
			
			}
	
			else if(strcmp(opcode,"WORD")==0){
			
				lc=lc+3;
				
				
			}
			else if (strcmp(opcode,"BYTE")==0){
				lc=lc+strlen(operand);
				
				cc++;
			}
			else if (strcmp(opcode,"RESW")==0)
			lc=lc+(atoi(operand)*3);
			else if (strcmp(opcode,"RESB")==0)
			lc=lc+(atoi(operand));
			else if (strcmp(opcode,"EQU")==0){
			
			
			
			
			
		}
			
			else {
				rewind(optab);
				if(opcode[0]=='+'){
				
				lc=lc+4;
				
				
			}
				
				else{
				
			fscanf(optab,"%s%s%s",opcodet,format,mnemonic);
					while (strcmp(opcode,opcodet)!=0){
					fscanf(optab,"%s%s%s",opcodet,format,mnemonic);	
									
				
	}
	lc=lc+atoi(format);
		
		}
		
		}
		if(operand[0]=='='){
			
			strcpy(a[k],operand);
			printf("%s",a[k]);
			k++;

		}
		
		
			if(strcmp(opcode,"RESW")==0||strcmp(opcode,"RESB")||cc>10){
				kk++;
				cc=1;
				
			}
			
			fscanf(code,"%s\t%s\t%s",label,opcode,operand);
			
		}
		if(k>0){
			fprintf(med,"%s\t%s\t%s\t - \n",label,opcode,operand);
					for(int i=0;i<=k-1;i++){
					
					strcpy(ex,a[i]);
					fprintf(literalw,"%s\t",ex);
					
					printstr(literalw,ex);
					
					fprintf(literalw,"\t%d\t%04x\n",strlen(ex)-4,lc);
					fprintf(med,"*\t%s\t-\t%04x\n",ex,lc);
					
					lc=lc+strlen(ex)-4;	
		}
	}
	else{
		fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
	}
		end=lc;
	
		rewind(med);
		fscanf(med,"%s%s%s%s",label,opcode,operand,location);
		fscanf(med,"%s%s%s%s",label,opcode,operand,location);
		fscanf(med,"%s%s%s%s",label,opcode,operand,location);
			
		
		rewind(symb);
		rewind(optab);
		rewind(literalw);
		lc=0;
	while(strcmp(opcode,"END")!=0){
				if(strcmp(opcode,"LDB")==0){
						rewind(symb);	
					fscanf(symb,"%s%s",labelsy,lcsy);
			
			
					while (strcmp(operand,labelsy)!=0){
					
					fscanf(symb,"%s%x",labelsy,&sy);

				}
				rewind(symb);
				 base=sy;
				
					
				}

				if(strcmp(opcode,"WORD")==0){
				
					fprintf(obj,"%s\t%s\t%s\t %04x \t\t",label,opcode,operand,lc);					
					fprintf(obj,"%06x\n",atoi(operand));

				}
				
				else if(strcmp(opcode,"RESW")==0||strcmp(opcode,"RESB")==0){
					strcpy(object,"-");
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t    %s\n",label,opcode,operand,lc,object);
		
				}
				else if (strcmp(opcode,"EQU")==0){
					strcpy(object,"-");
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t    %s\n",label,opcode,operand,lc,object);
					
					
				}
					else if (strcmp(opcode,"LTORG")==0){
					strcpy(object,"-");
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t    %s\n",label,opcode,operand,lc,object);
					
					
				}
				
				
				else if(strcmp(opcode,"BYTE")==0){
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					printstr(obj,operand);
					fprintf(obj,"\n");
	
				}
				
				
					else if(opcode[0]=='='){
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					printstr(obj,opcode);
					fprintf(obj,"\n");
					
	
	
				}
				
				
				
				
				else if (operand[strlen(operand)-2]==','){
					printf("hello");
					rewind(optab);
					fscanf(optab,"%s%s%x",opcodet,format,&mn);
					while (strcmp(opcode,opcodet)!=0)
					fscanf(optab,"%s%s%x",opcodet,format,&mn);	
				rewind(optab);
					
					mn=mn+3;
				
					
					rewind(symb);
					fscanf(symb,"%s%s",labelsy,lcsy);
						strcpy(ex,labelsy);
						strcat(ex,",X");
						
					
						
					while (strcmp(operand,ex)!=0){
					
					fscanf(symb,"%s%x",labelsy,&sy);
						strcpy(ex,labelsy);
						strcat(ex,",X");
					}
					
					rewind(symb);
				
					
					disp=sy-(lc+atoi(format));
					if(disp>-2048&&disp<2047){
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02xa",mn);
					fprintf(obj,"%03x\n",disp);

					}
					
				}
				
				
				else if(opcode[0]=='+'){
					
					m[r]=lc;
					r++;

					fscanf(optab,"%s%s%x",opcodet,format,&mn);
					strcpy(format4,"+");
					strcat(format4,opcodet);
					
					
			
				
					while (strcmp(opcode,format4)!=0){
					
					fscanf(optab,"%s%s%x",opcodet,format,&mn);
					strcpy(format4,"+");
					strcat(format4,opcodet);
					}
					rewind(optab);
					mn=mn+3;
				
			
			
					
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x1",mn);
					fscanf(symb,"%s%s",labelsy,lcsy);
					
				
					

					while (strcmp(operand,labelsy)!=0)
					fscanf(symb,"%s%x",labelsy,&sy);	
					rewind(symb);
						fprintf(obj,"%05x\n",sy);
					
					
					
					
					
					
					
			}
			
			else {
					rewind(optab);
					fscanf(optab,"%s%s%x",opcodet,format,&mn);
					while (strcmp(opcode,opcodet)!=0)
					fscanf(optab,"%s%s%x",opcodet,format,&mn);	
				rewind(optab);
				
				if(atoi(format)==1){
					
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t%02x\n",label,opcode,operand,lc,mn);
					
				}
					else if(atoi(format)==2){
					
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t%02x",label,opcode,operand,lc,mn);
					if(operand[0]=='A')
					fprintf(obj,"00\n");
					else if (operand[0]=='X')
					fprintf(obj,"10\n");
					else if (operand[0]=='L')
					fprintf(obj,"20\n");
					
					
					
				}
		
		
				
				else if(operand[0]!='@'&&operand[0]!='='&&operand[0]!='#'){
					mn=mn+3;
					rewind(symb);	
					fscanf(symb,"%s%s",labelsy,lcsy);
			
			
					while (strcmp(operand,labelsy)!=0){
					
					fscanf(symb,"%s%x",labelsy,&sy);
					
					
				}
					rewind(symb);
			
			
				
					disp=sy-(lc+atoi(format));
					printf("base is %x",base);
					if(disp>-2048&&disp<2047){
					if(disp>0){
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x2",mn);
					fprintf(obj,"%03x\n",disp);
				}
				else {
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x2",mn);
					fprintf(obj,"%03hx\n",disp);
					
				}

					}
					else if(disp>0&&disp<4095){
						
						disp=sy-base;
						fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x4",mn);
					fprintf(obj,"%03x\n",disp);
						
					}
				}
		
				
					else if (operand[0]=='='){
						mn=mn+3;
					rewind(literalw);
					fscanf(literalw,"%s%s%s%x",labelsy,hex,operand1,&sy);
					while (strcmp(operand,labelsy)!=0){
					fscanf(literalw,"%s%s%s%x",labelsy,hex,operand1,&sy);	
				}
					rewind(literalw);
					disp=sy-(lc+atoi(format));
					if(disp>-2048&&disp<2047){
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x2",mn);
					
					fprintf(obj,"%03x\n",disp);
						
						}
					}
				

				
				
				else if (operand[0]=='@'){
					mn=mn+2;
					strcpy(ex,&operand[1]);
					
					fscanf(symb,"%s%s",labelsy,lcsy);
					while (strcmp(ex,labelsy)!=0)
					fscanf(symb,"%s%x",labelsy,&sy);	
					rewind(symb);
					disp=sy-(lc+atoi(format));
					if(disp>-2048&&disp<2047){
					
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x2",mn);
					fprintf(obj,"%03x\n",disp);
					
				}
					
					
				}
			
			
				else if (operand[0]=='#'){
					mn=mn+1;
					strcpy(ex,&operand[1]);
					disp=atoi(ex);
					printf("%d",lc);
					fprintf(obj,"%s\t%s\t%s\t  %04x\t\t",label,opcode,operand,lc);
					fprintf(obj,"%02x0",mn);
					fprintf(obj,"%03x\n",disp);
					
					
					
					
					
					
				}
				
				

	}	

					fscanf(med,"%s%s%s%x",label,opcode,operand,&lc);
					

			}
		
			fprintf(obj,"%s\t%s\t%s\t  %s\t\t     -",label,opcode,operand,location);
		
		rewind(obj);
		fscanf(obj,"%s%s%s%s%s",label,opcode,operand,location,object);
		fscanf(obj,"%s%s%s%s%s",label,opcode,operand,location,object);
		fprintf(hte,"H.%s.%06x.%06x\n",opcode,start,end-start);
		fscanf(obj,"%s%s%s%s%s",label,opcode,operand,location,object);
		htlength[0]=44;
		htlength[2]=3;
		kk=0;
		fprintf(hte,"T.%06s.%02x",location,htlength[kk]);
		k++;
		
		
		while(strcmp(opcode,"END")!=0){
			start=0;
		if(index>10){
			index=1;
			fprintf(hte,"\nT.%06s.%02x",location,htlength[kk]);
			kk++;
			
		}
		if(strcmp(object,"-")==0){
			index=1;
			fprintf(hte,"\n");
			c=0;
			
		}
		if(strcmp(object,"-")!=0&&c==0){
		fprintf(hte,"T.%06s.%02x",location,htlength[kk]);
		kk++;
		c=1;
	}
		if(strcmp(object,"-")!=0){
		fprintf(hte,".%06s",object);
	}
			
			index++;
		fscanf(obj,"%s%s%s%s%s",label,opcode,operand,location,object);
	
		}
		for (int i=0;i<=r-1;i++){
			fprintf(hte,"M.%06x.05\n",m[i]);
		
			
		}
		
		fprintf(hte,"\nE.%06x",start);
		printf("%s",fhte);
		
		
			
				
			
			
			
			
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	}
			
		
			
			
		
		
			
			
	
				

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

			
		
			
			
		
		
			
			
	
			

	
