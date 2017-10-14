/*
kartik 
1143
First attempt to write a program for Color Detection
 */
 
 
 
 #include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace std;
using namespace cv;
int getcolour(char* colour,char* positions)
{
		int x=480;
		int y,m,n,a,b,k,t=0;float c,d;
		int astart,bstart,i,hvalue,svalue,vvalue,success;
          	//char colour[54];
		y=x/7;
		Vec3b intensity;
		 namedWindow("Camera", CV_WINDOW_AUTOSIZE); //create a window called "Control"
                for (k=0;k<6;k++)
                {
                success=1;
		Mat frame,image;
                VideoCapture cap(0); //open camera no. 0 (internal)  EDIT : Changed 0 to 1
                 while(waitKey(30)!=27)
                {
                                cap >> image; //save captured image to frame variable
                                 //flip(image,image,1); 
                                //resize(frame, frame, Size(x, x), 0, 0, INTER_CUBIC);
                                
                                
                            /*    line( frame, Point(y, 0 ), Point( y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 2*y, 0 ), Point( 2*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 3*y, 0), Point( 3*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 4*y, 0 ), Point( 4*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 5*y, 0 ), Point( 5*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 6*y, 0 ), Point( 6*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point( 7*y, 0 ), Point( 7*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                                
                                
                                
                                line( frame, Point(0,y), Point( 7*y,y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0, 2*y), Point(7*y, 2*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0, 3*y), Point(7*y, 3*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0, 4*y ), Point( 7*y,4*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0, 5*y ), Point( 7*y,5*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0,6*y), Point(7*y, 6*y), Scalar( 0, 0, 0 ),  2, 8 );
                                line( frame, Point(0, 7*y), Point(7*y, 7*y), Scalar( 0, 0, 0 ),  2, 8 );
                               */
                                
                              
                              
                              for(m=0;m<3;m++)
                              {
                              	for(n=0;n<3;n++)
                              	{
                              		a=y*(2*m+1)+80;
                              		b=y*(2*m+2)+80;
                              		c=y*(2*n+1);
                              		d=y*(2*n+2);
                              		line( image, Point(a,c), Point(b,c), Scalar( 0, 0, 0 ),  2, 8 );
                              		line( image, Point(a,c), Point(a,d), Scalar( 0, 0, 0 ),  2, 8 );
                              		line( image, Point(a,d), Point(b,d), Scalar( 0, 0, 0 ),  2, 8 );
                              		line( image, Point(b,c), Point(b,d), Scalar( 0, 0, 0 ),  2, 8 );
                              		
                              		
                              		
                              	}
                              }
                              
                              
                              
                              
                                
                                imshow("Camera",image); //show image on window named Camera
                }
                cout<<" Milestone 0 reached "<<endl;
               
                
                 cvtColor(image,frame, CV_BGR2HSV);
                
                
                vector<int> compression_params; //vector that stores the compression parameters of the image

     		compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

     		compression_params.push_back(98); //specify the compression quality



     		bool bSuccess = imwrite("image.jpg", frame, compression_params); //write the image to file
     		
     		int index=0,centre[9]; float avgh[9],avgs[9],avgv[9];
     		
     		
     		
     		
     		cout<<"Reached milestone 1 "<<endl;
     		
     		for(n=0;n<3;n++)//Find the highest and lowest H value for each box
     		{
     			for(m=0;m<3;m++)
     			{
     				
     				
     				
     				astart=y*(2*m+1)+4+80;
				bstart=y*(2*n+1)+4;
     				intensity = frame.at<Vec3b>(bstart,astart);
				hvalue= intensity.val[0];
				svalue= intensity.val[1];
				vvalue= intensity.val[2];
				
     				
			        avgh[index]=0;
                                avgs[index]=0;
                                avgv[index]=0;
				
     				
     				
     				for(a=astart;a<y*(2*m+2)-4+80;a++)
     				{
     					for(b=bstart;b<y*(2*n+2)-4;b++)
     					{
     					
     					
     					
     					      	intensity = frame.at<Vec3b>(b,a);
					          hvalue= intensity.val[0];
                                                  avgh[index]=avgh[index]+(hvalue)/3669.0;
   
     						
     						  svalue= intensity.val[1];
                                                  avgs[index]=avgs[index]+(svalue)/3669.0;

                                                  vvalue= intensity.val[2];
                                                  avgv[index]=avgv[index]+(vvalue)/3669.0;
   
   
     						
     						
     					}
     				}
                     		c=y*((2*m+1)+0.5)+4+80;
				d=y*((2*n+1)+0.5)+4;

                                intensity = frame.at<Vec3b>(d,c);
				hvalue= intensity.val[0];
                                centre[index]=hvalue;
                                cout<<"colour of box"<<index+1<<endl;
                                
                                if(( centre[index]>=0 && centre[index]<=6)||( centre[index]>=160 && centre[index]<=179))//Originally 0-13
				{
				 //cout<<"red"<<endl;
				putText(image, "R", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='R';
			        }
			        else if(avgh[index]>=7 && avgh[index]<=20)  //Originally 14-20
                                {
				 //cout<<"orange"<<endl;
				putText(image, "O", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='O';
				}
 				else if(avgh[index]>=25 && avgh[index]<=43)//Original 27
                                {
				 //cout<<"yellow"<<endl;
				putText(image, "Y", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='Y';
			        }
                                else if(avgs[index]<=70 )
                                {
	
				 //cout<<"white"<<endl;
				putText(image, "W", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='W';
			        }
				else if(avgh[index]>=47 && avgh[index]<=95)  //Originally 80
                                {
				 //cout<<"green"<<endl;
				putText(image, "G", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='G';
			        }
				else if(avgh[index]>=100 && avgh[index]<=120)
                                {
				 //cout<<"blue"<<endl;
				putText(image, "B", cvPoint(c,d), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
				colour[t]='B';
			        }
				else
				{
				cout<<"Face "<<k<<" not detcted properly , Try again "<<endl;
				success=0;
				colour[t]=0;
				
				}
				
     				index++;t++;
     			}
     		}
	         
	         
     		 imshow("Camera",image); //show image on window named Camera
     		
     		cout<<"Reached milestone 2 "<<endl;
     		  		
     		if(success==0)
     		{
     			index-=9;
     			t-=9;
     			k--;
     			waitKey(10000);
     			continue;
     		}
     		/*cout<<"The avg hsv values of colors were calculated , The result is as follows "<<endl;
     		for(int i=0;i<9;i++)
     		{
     			cout<<"Color "<<i<<endl;
     			
     			cout<<"avg H :  "<<avgh[i]<<endl;
     		
     			cout<<endl;
     			
     			cout<<"avg S :  "<<avgs[i]<<endl;
     		
     			cout<<endl;
     			
     			cout<<"avg V :  "<<avgv[i]<<endl;
     		
     			cout<<endl;
     		}
     		*/
     		
     		
     		cout<<"Press R/r if there is a problem with colour detection "<<endl;
     		
     		
     		if(waitKey(5000)=='r')
     		{
     			index-=9;
     			t-=9;
     			k--;
     			cout<<"Try again  "<<endl;
     			continue;
     		}
     		cout<<"Face "<<k+1<<" detected successfully , now put next face  "<<endl;
     		
     		
     		}
		for(int i=0;i<54;i++)
		{

		//cout<<"colour "<<i+1<<endl;
                //cout<<colour[i]<<endl;
		}
		
		
  char c1[12][2],c2[8][3];
  
  
  i=0;
  int number[]={44,2,42,11,38,20,40,29,47,8,51,17,53,26,49,35,6,13,4,33,22,15,24,31};
  int num[]={45,3,10,39,12,19,37,21,28,43,30,1,48,16,9,46,7,36,52,34,27,54,25,18};
  for(m=0;m<12;m++)
  { 
     for(n=0;n<2;n++,i++)
     {
     
     
     if(colour[number[i]-1]=='Y')
     {  c1[m][n]='U';
     }                    
      else if(colour[number[i]-1]=='R')
     {  c1[m][n]='F';
     }                 
      else if(colour[number[i]-1]=='G')
     {  c1[m][n]='L';
     }                 
      else if(colour[number[i]-1]=='O')
     {  c1[m][n]='B';
     }                 
      else if(colour[number[i]-1]=='B')
     {  c1[m][n]='R';
     }                 
      else if(colour[number[i]-1]=='W')
     {  c1[m][n]='D';
     }                 
      
     
     
     }
  }
  
  i=0;
   for(m=0;m<8;m++)
  { 
     for(n=0;n<3;n++,i++)
     {
     
     
     if(colour[num[i]-1]=='Y')
     {  c2[m][n]='U';
     }                    
      else if(colour[num[i]-1]=='R')
     {  c2[m][n]='F';
     }                 
      else if(colour[num[i]-1]=='G')
     {  c2[m][n]='L';
     }                 
      else if(colour[num[i]-1]=='O')
     {  c2[m][n]='B';
     }                 
      else if(colour[num[i]-1]=='B')
     {  c2[m][n]='R';
     }                 
      else if(colour[num[i]-1]=='W')
     {  c2[m][n]='D';
     }                 
      
     
     
     }
  }
  
  
 int myindex=0;
 		for(m=0;m<12;m++)
  		{ 
     			for(n=0;n<2;n++)
     			{
        			positions[myindex++]=c1[m][n];cout<<c1[m][n];
      			}
      			positions[myindex++]=' ';cout<<" ";
   		}
   
   
   
  		for(m=0;m<8;m++)
  		{ 
     			for(n=0;n<3;n++)
     			{
         			positions[myindex++]=c2[m][n];cout<<c2[m][n];
     			}
     			positions[myindex++]=' ';cout<<" ";  
 		}
 		positions[myindex]='\0';//To ensure that the algorithm does not get garbage at the end
 		
 		destroyWindow("Camera");
}

