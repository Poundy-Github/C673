"""
stk/util/email
--------------

Module for sending e-mails

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:38CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import smtplib
import win32com.client

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class Smtp:
    """
    Smtp class is a simple class for writing e-mails with an available Smtp Server.

    :author:        Robert Hecker
    :date:          06.05.2013
    """

    def __init__(self, server="smtphub07.conti.de"):
        """
        Initialize all member variables.

        :param server: SMTPServer to use
        :type  server: string

        :author:        Robert Hecker
        :date:          06.05.2013
        """

        self._server = server

    def sendmail(self, send_from, send_to, subject, body):
        """
        Send a email with subject and message to a single receiver or a list of receivers.

        :param send_from: sender address
        :type  send_from: string
        :param send_to: single receiver address or list of addresses
        :type  send_to: string or list of strings
        :param subject: Subject of E-Mail
        :type  subject: string
        :param body: Message of E-Mail
        :type  body: string

        :author:        Robert Hecker
        :date:          06.05.2013
        """
        if(subject is not None):
            body = 'Subject: %s\n\n%s' % (subject, body)

        # Append Footnote to the Body, to see, which User send the mail.
        body += "\n"
        body += "\n"
        temp = "email send via stk.util.email.Smtp from the UserID: %s" % (os.environ["username"])
        body += "-" * len(temp) + "\n"
        body += temp

        server = smtplib.SMTP(self._server)
        server.sendmail(send_from, send_to, body)
        server.quit()


class NotesMail(object):
    """
    NotesMail uses an existing Notes Session to write a e-mail.

    :author:        Robert Hecker
    :date:          06.05.2013
    """
    def __init__(self):
        pass

    def sendmail(self, send_to, subject, body, attachments=[]):
        """
        Use Notes to send an email from the current user

        :param recipients: a list of email addresses to send to
                           (or full names from the notes address book)
        :type  recipients: list of string
        :param subject: subject of the email
        :type  subject: string
        :param body: Message of E-Mail
        :type  body: string
        :param attachments: list of full path and filenames to attach to the email
        :type  attachments: list of strings (paths)

        :notes: body: empty lines didn't seem to come through properly for me, I had to
                include at least a space on each line to keep them from disappearing.
                This will send email from the currently active Notes account, and ask you for a
                password if you're not logged in - so, it would probably need some kind of
                modification to be used unattended on a server somewhere...
                If you want to extend this, you can find more documentation on the Notes COM API
                at http://www.lotus.com/developers/devbase.nsf/homedata/homecom
                a windows help version can be had by following the "Download Now" link on that
                page and scrolling to the bottom of the page.
                (There may be better stuff out there, this is just the first thing I found. ;)

        :author:        Robert Hecker
        :date:          06.05.2013
        """

        sess = win32com.client.Dispatch("Notes.NotesSession")
        db = sess.getdatabase('', '')
        db.openmail
        doc = db.createdocument

        # Set the recipient to the current user as a default
        if not send_to:
            send_to = sess.UserName

        doc.SendTo = send_to
        doc.Subject = subject

        rti = doc.createrichtextitem('Body')
        rti.AppendText(body)

        # Notes attachments get made in RichText items...
        if attachments:
            rt = doc.createrichtextitem('Attachment')
            for path in attachments:
                rt.embedobject(1454, '', path)

        doc.Send(0)

"""
$Log: email.py  $
Revision 1.1 2021/12/13 17:59:38CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.3 2013/09/09 11:41:39CEST Hecker, Robert (heckerr) 
Added UserID into footer of the email-body.
- Added comments -  heckerr [Sep 9, 2013 11:41:40 AM CEST]
Change Package : 196670:1 http://mks-psad:7002/im/viewissue?selection=196670
Revision 1.2 2013/08/27 08:34:39CEST Hecker, Robert (heckerr) 
Corrected parameter documentation.
--- Added comments ---  heckerr [Aug 27, 2013 8:34:39 AM CEST]
Change Package : 195099:1 http://mks-psad:7002/im/viewissue?selection=195099
Revision 1.1 2013/05/07 08:52:02CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
"""
