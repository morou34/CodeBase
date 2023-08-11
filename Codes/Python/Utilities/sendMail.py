import smtplib
import os
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

sender_email = "mouaadproterminal@outlook.fr"
receiver_email = "younispro86@gmail.com"
password = "YAb792JHACU6QKrYYu7n"

msg = MIMEMultipart()
msg["From"] = sender_email
msg["To"] = receiver_email
msg["Subject"] = "remise TP1"

# Add the body of the email
body = "Here are your files for TP1. \nGood Luck\nMouaad"
msg.attach(MIMEText(body, "plain"))

# Add the attachment
filename = "output.zip"
filepath = os.path.join(os.getcwd(), filename)
print(filepath)
part = MIMEBase("application", "octet-stream")
part.set_payload(open(filepath, "rb").read())
encoders.encode_base64(part)
part.add_header("Content-Disposition", f"attachment; filename= {filename}")
msg.attach(part)

# Send the email
with smtplib.SMTP("smtp.outlook.com", 587) as server:
    server.ehlo()
    server.starttls()
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, msg.as_string())

