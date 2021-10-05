import cv2
import pandas as pd

pathOfFile = 'C:\Users\Desktop'  #Enter path of certificate template
uniqueCertificateCode='exampleCode'  #Enter a unique code for certificate
fileName='template.png' #Enter file name of certificate template
personName='John Doe' #Name of person to display
certiCode = "Certificate Id: "+uniqueCertificateCode

image=cv2.imread(pathOfFile+fileName)

org=(500,880)  #Enter coordinates onto where the name is to be displayed on the file
fontScale = 0.7  #Font Size of text to create
color=(255,255,255)  #Color of name displayed
font=cv2.FONT_HERSHEY_SIMPLEX  #Font
thickness=1 #Thickness
new_image = cv2.putText(image, certiCode, org, font, fontScale,  
                color, thickness, cv2.LINE_AA, False)   #Create final certificate with name and unique code

cv2.imwrite(f"pathOfFile/{personName}.jpeg", new_image)  #Save the certificate