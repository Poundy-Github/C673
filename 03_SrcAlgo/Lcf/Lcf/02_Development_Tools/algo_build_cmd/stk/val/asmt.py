"""
stk/val/asmt.py
-------------------

 Subpackage for Handling Assessment Class and States

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:44CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import logging

# Import STK Modules ----------------------------------------------------------
import stk.db.gbl.gbl as db_gbl
import stk.db.val.val as db_val
import stk.db.cat.cat as db_cat
from stk.db.db_common import SQLite3BaseDB


class ValAssessmentStates():
    """ Base class for assessments states
    """
    PASSED = "Passed"
    FAILED = "Failed"
    INVESTIGATE = "Investigate"
    NOT_ASSESSED = "Not Assessed"

    def __init__(self, obs_type):
        """
        Constructor for Assessment class
        @param obs_type: Name of the observer type
        """
        self.__states = []
        self.__type = obs_type

    def Load(self, dbi_gbl):
        """ Load the assessment states
        @param db: global db interface
        @return: True on passed, False on Error
        """
        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False
        obs_type_id = dbi_gbl.GetValObserverTypeId(self.__type)
        self.__states = dbi_gbl.GetAssessmentState(observer_type_id=obs_type_id)
        return True

    def Save(self, dbi_gbl):
        """ Save the assessment states
        @param dbi_gbl: GBL Database interface
        """
        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        obs_type_id = dbi_gbl.GetValObserverTypeId(self.__type)
        for state in self.__states:
            if db_gbl.COL_NAME_ASSESSMENT_STATE_ASSID not in state:
                state[db_gbl.COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID] = obs_type_id
                dbi_gbl.AddAssessmentState(state)

        return True

    def AddState(self, name, desc):
        """ Get the Result Name
        """
        for state in self.__states:
            if name.lower() == state[db_gbl.COL_NAME_ASSESSMENT_STATE_NAME]:
                return False
        self.__states.append({db_gbl.COL_NAME_ASSESSMENT_STATE_NAME: name,
                              db_gbl.COL_NAME_ASSESSMENT_STATE_DESCRIPTION: desc})
        return True

    def GetType(self):
        """ Get the Result Name
        """
        return self.__type

    def GetStates(self, with_id=False):
        """ Return the list of assessment states or a key / value dictonary with ID and Name
        """
        if with_id is False:
            state_list = []
            for state in self.__states:
                state_list.append(state[db_gbl.COL_NAME_ASSESSMENT_STATE_NAME])

        else:
            state_list = {}
            for state in self.__states:
                state_list[state[db_gbl.COL_NAME_ASSESSMENT_STATE_ASSID]] = \
                    state[db_gbl.COL_NAME_ASSESSMENT_STATE_NAME]

        return state_list

    def GetStateId(self, state_name):
        """ Get State Identifier of the given Assessment
        @param state_name: Assessment State name
        """
        for state in self.__states:
            if state_name.lower() == state[db_gbl.COL_NAME_ASSESSMENT_STATE_NAME].lower():
                return state[db_gbl.COL_NAME_ASSESSMENT_STATE_ASSID]

    def GetStateName(self, state_id):
        """ Get Assessment State by given Identifier
        @param state_name: Assessment State Identifier
        """
        for state in self.__states:
            if state_id == state[db_gbl.COL_NAME_ASSESSMENT_STATE_ASSID]:
                return state[db_gbl.COL_NAME_ASSESSMENT_STATE_NAME]


class ValAssessmentWorkFlows():
    """ Base class for assessments workflows
    """
    ASS_WF_AUTO = "automatic"
    ASS_WF_MANUAL = "manual"
    ASS_WF_REVIEWED = "verified"
    ASS_WF_REJECTED = "rejected"

    def __init__(self):
        """ Initialize the workflow class
        """
        #  List of Workflow States
        self.__workflows = []
        self.__workflow_list = [ValAssessmentWorkFlows.ASS_WF_AUTO,
                                ValAssessmentWorkFlows.ASS_WF_MANUAL,
                                ValAssessmentWorkFlows.ASS_WF_REVIEWED,
                                ValAssessmentWorkFlows.ASS_WF_REJECTED]
        #  Observer Type
        self.__type = type

    def Load(self, dbi_gbl):
        """ Load the assessment states
        @param dbi_gbl: global db interface
        @return: True on passed, False on Error
        """
        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        for wf_name in self.__workflow_list:
            wf = dbi_gbl.GetWorkflow(wf_name)
            if db_gbl.COL_NAME_WORKFLOW_WFID in wf:
                self.__workflows.append(wf)
        return True

#    def save(self, db):
#        """ Save the workflow states - not supported
#        """
#        if not issubclass(db.__class__, db_gbl.BaseGblDB):
#            return False
#
#        return False

#    def addState(self, name, desc):
#        """ Add a new workflow state - not supported
#        """
#        for state in self.__workflows:
#            if name.lower() == state[db_gbl.COL_NAME_WORKFLOW_NAME]:
#                return False
#
#        self.__workflows.append({db_gbl.COL_NAME_WORKFLOW_NAME:name,
#                              db_gbl.COL_NAME_WORKFLOW_DESC:desc,
#                              })
#        return True

    def GetStates(self):
        """ Return the list of workflow states
        """
        state_list = []
        for state in self.__workflows:
            state.append(state[db_gbl.COL_NAME_WORKFLOW_NAME])

        return state_list

    def GetStateId(self, wf_name):
        """ Get Workflow State
        @param wf_name:
        """
        for state in self.__workflows:
            if wf_name.lower() == state[db_gbl.COL_NAME_WORKFLOW_NAME].lower():
                return state[db_gbl.COL_NAME_WORKFLOW_WFID]

        return None

    def GetStateName(self, wf_id):
        """ Get Workflow State
        @param wf_id:
        """
        for state in self.__workflows:
            if wf_id == state[db_gbl.COL_NAME_WORKFLOW_WFID]:
                return state[db_gbl.COL_NAME_WORKFLOW_NAME]

        return None


class ValAssessment():
    """ Base class for assessments
    """
    def __init__(self,
                 user_id=None,
                 wf_state=None,
                 ass_state=None,
                 ass_comment=None,
                 date_time=None,
                 issue=None):
        """
        @param user_id: User Id
        @param wf_state: Workflow State
        @param ass_state: Assessment State
        @param ass_comment: Assessment Comment
        @param issue: Issue name from MKS
        """
        self.__user_id = user_id
        self.__wf_state = wf_state
        self.__ass_state = ass_state
        self.__ass_comment = ass_comment
        self.__date_time = date_time
        self.__issue = issue
        self.__id = None
        self.__ass_states = None
        self.__ass_wf = None

    def __str__(self):
        """ Return the Assessment as String
        """
        txt = "ValAssessment:\n"
        if self.__id is not None:
            txt = txt + str(" ID: %s" % self.__id)
        else:
            txt = txt + str(" ID: -")

        txt = txt + str(" Status: '%s'" % self.__wf_state)
        txt = txt + str(" Result: '%s'" % self.__ass_state)
        if self.__issue is not None:
            txt = txt + str(" Issue: %s" % self.__issue)

        txt = txt + str(" Date: %s" % self.__date_time)
        txt = txt + str(" Info: '%s'" % self.__ass_comment)
        return txt

    def Load(self, ass_id, dbi_val, dbi_gbl, val_obs_name):
        """ The Assessment from DB

        @param ass_id: Assessment ID
        @param val_dbi: VAL Database interface
        @param gbl_dbi:  GBL Database interface
        """
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        self.__LoadStates(dbi_gbl, val_obs_name)

        entries = dbi_val.GetAssessment(ass_id)
        if len(entries) == 0:
            logging.error("No result for Assessment ID was not found")
            return False
        elif len(entries) == 1:
            record = entries[0]
            self.__id = record[db_val.COL_NAME_ASS_ID]
            self.__user_id = record[db_val.COL_NAME_ASS_USER_ID]
            self.__ass_comment = record[db_val.COL_NAME_ASS_COMMENT]
            self.__date_time = record[db_val.COL_NAME_ASS_DATE]
            self.__issue = record[db_val.COL_NAME_ASS_TRACKING_ID]
            wf_id = record[db_val.COL_NAME_ASS_WFID]
            self.__wf_state = self.__ass_wf.GetStateName(wf_id)

            assst_id = record[db_val.COL_NAME_ASS_ASSSTID]
            self.__ass_state = self.__ass_states.GetStateName(assst_id)
            return True

        return False

    def Save(self, dbi_val, dbi_gbl, val_obs_name):
        """ Save the result
        """
        record = {}
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        self.__LoadStates(dbi_gbl, val_obs_name)
        if self.__user_id is None:
            user = dbi_gbl.GetUser(login=os.environ["USERNAME"])
            self.__user_id = user[db_gbl.COL_NAME_USER_ID]
        record[db_val.COL_NAME_ASS_USER_ID] = self.__user_id
        record[db_val.COL_NAME_ASS_COMMENT] = self.__ass_comment
        record[db_val.COL_NAME_ASS_TRACKING_ID] = self.__issue
        wf_id = self.__ass_wf.GetStateId(self.__wf_state)
        record[db_val.COL_NAME_ASS_WFID] = wf_id

        if self.__date_time is None and issubclass(dbi_gbl.__class__, SQLite3BaseDB):
            self.__date_time = dbi_gbl.GetCurrDateTime()

        record[db_val.COL_NAME_ASS_DATE] = self.__date_time
        assst_id = self.__ass_states.GetStateId(self.__ass_state)
        record[db_val.COL_NAME_ASS_ASSSTID] = assst_id

        self.__id = dbi_val.AddAssessment(record)
#        self.__id = dbi_val.GetAssessmentId(assstid=assst_id,
#                                            asscomment=self.__ass_comment,
#                                            wfid=wf_id,
#                                            userid=self.__user_id)

        return True

    def Update(self, dbi_val, dbi_gbl, val_obs_name):
        """ Update the Assessment"""
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False
        if self.__id is None:
            logging.error("Cannot Update Unsaved/Unloaded Assessment")
            return False
        else:
            record = {}
            user = dbi_gbl.GetUser(login=os.environ["USERNAME"])
            self.__user_id = user[db_gbl.COL_NAME_USER_ID]
            record[db_val.COL_NAME_ASS_ID] = self.__id
            record[db_val.COL_NAME_ASS_USER_ID] = self.__user_id
            record[db_val.COL_NAME_ASS_COMMENT] = self.__ass_comment
            record[db_val.COL_NAME_ASS_TRACKING_ID] = self.__issue
            assst_id = self.__ass_states.GetStateId(self.__ass_state)
            record[db_val.COL_NAME_ASS_ASSSTID] = assst_id
            if issubclass(dbi_gbl.__class__, SQLite3BaseDB):
                self.__date_time = dbi_gbl.GetCurrDateTime()
            else:
                self.__date_time = None
            record[db_val.COL_NAME_ASS_DATE] = self.__date_time
            wf_id = self.__ass_wf.GetStateId(ValAssessmentWorkFlows.ASS_WF_MANUAL)
            record[db_val.COL_NAME_ASS_WFID] = wf_id
            dbi_val.UpdateAssessment(record)
            self.Load(self.__id, dbi_val, dbi_gbl, val_obs_name)

    def __LoadStates(self, dbi_gbl, val_obs_name):
        """ Load the States """

        if self.__ass_states is None:
            self.__ass_states = ValAssessmentStates(val_obs_name)
            self.__ass_states.Load(dbi_gbl)

        if self.__ass_wf is None:
            self.__ass_wf = ValAssessmentWorkFlows()
            self.__ass_wf.Load(dbi_gbl)

    def GetUserId(self):
        """ Get the User Name
        """
        return self.__user_id

    def GetId(self):
        """ Get the Assessment Identifier
        @return: Assessment ID
        """
        return self.__id

    def GetComment(self):
        """ Get the Assessment Comment
        @return: Assessment Comment
        """
        return self.__ass_comment

    def SetComment(self, comment):
        """ Set the Assessment Comment
        """
        self.__ass_comment = comment

    def GetAssesmentState(self):
        """ Get the Assessment State
        :return: assessment state
        """
        return self.__ass_state

    def SetAssesmentState(self, ass_state):
        """ Get the Assessment State
        """
        self.__ass_state = ass_state

    def GetIssue(self):
        """ Get the Issue status
        @return: Tracking id
        """
        return self.__issue

    def SetIssue(self, issue):
        """ Set the Assessment Comment
        """
        self.__issue = issue
