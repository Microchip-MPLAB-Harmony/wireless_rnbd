
Application_Menu_options = ["TRANSPARENT UART","BASIC DATA EXCHANGE","NONE"]
Module_Type_options      = ["RNBD","RN487x"]
Security_Options         = ["NON SECURE","SECURE"]
global rnHostLibFilesArray
rnHostLibFilesArray = []
global periphInstanceName
periphInstanceName = []
global SercomInstanceValue
SercomInstanceValue = 0
global TimerInstanceValue
TimerInstanceValue = 0
global RTCInstanceValue
RTCInstanceValue = 0
global rnHostLibobjects 
rnHostLibobjects = {"rnComponent":"",
                    "SercomComponent":"",
                    "DelayComponent": "",
                    "Sercom_oper_symb_ID":"",
                    "TrustZoneFile":"",
                    "DummyTrustZoneFile":"",}
                    
global peripheralTrustZone      
peripheralTrustZone = {}   
global SercomConnected
global DelayTimerConnected
SercomConnected = False
DelayTimerConnected = False 
global secureApiGenerationCheck
secureApiGenerationCheck = False
global TrustZoneFileGenCheck 
TrustZoneFileGenCheck = False 
global ConnectedInst 
ConnectedInst = {'InterfaceSercomInst':'',
                 'DelayServiceInst':'',}     
         

def handleMessage(messageID, args):
    #print("HanldeMessage",messageID,args)
    if messageID == 'Application_Selection_Update' and args['Application Type'] == 'TRANSPARENT UART' and args['Enable'] == True:
        Database.setSymbolValue("RNBD_Dependency_1","RN_HOST_UART_INST_FUNCTIONAL_USE","TRANSPARENT UART EXAMPLE")
    elif messageID == 'Application_Selection_Update' and args['Application Type'] == 'TRANSPARENT UART' and args['Enable'] == False:  
        components = Database.getActiveComponentIDs()
        #print("components",components)
                

def onAttachmentConnected(source, target):
    #global InterfaceSercomInst
    #global DelayServiceInst
    global symbolID_oper
    #print("onAttachmentConnected",source,target)
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    localID = localComponent.getID()
    connectID = source["id"]
    targetID = target["id"]  
    #print(source,target)
    #print("remoteId:",remoteID)
    #print("localComponent",localComponent.getID())
    InstUsed = localComponent.getSymbolByID("RN_HOST_UART_INST_USED")
    InstUsed.setValue(remoteID.upper())
    args = {"eventID":"","sercomInstID":"","Connected":False}
    #print(source,target)
    
    if connectID == "RNBD_USART_Dependency":
        if Database.getSymbolValue("RNBD_Dependency_0","RN_HOST_UART_INST_FUNCTIONAL_USE") == "BLE USART INTERFACE" and localComponent.getID() == 'RNBD_Dependency_0':
            args.update({"eventID":"BLE_INTERFACE","sercomInstID":str(remoteID),"Connected": True})
            Database.sendMessage("RNBD_Dependency","SERCOM_INST_UPDATE",args)
        elif Database.getSymbolValue("RNBD_Dependency_1","RN_HOST_UART_INST_FUNCTIONAL_USE") == "TRANSPARENT UART EXAMPLE" and localComponent.getID() == 'RNBD_Dependency_1':
            args.update({"eventID":"TRANSPARENT_UART_INTERFACE","sercomInstID":str(remoteID),"Connected": True})
            Database.sendMessage("RNBD_Dependency","SERCOM_INST_UPDATE",args)
        symbolID_oper = remoteComponent.getSymbolByID("USART_OPERATING_MODE")
        usart_Operating_mode = symbolID_oper.getSelectedKey()       
        if usart_Operating_mode != 'RING_BUFFER':
            symbolID_oper.setSelectedKey("RING_BUFFER")
        symbolID_oper.setReadOnly(True)
        
    
        
    
def onAttachmentDisconnected(source, target):
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    localID = localComponent.getID()
    connectID = source["id"]
    targetID = target["id"]
    #print("onAttachmentDisconnected")
    args = {"eventID":"","sercomInstID":"","Connected":False}
    if source["id"] == "RNBD_USART_Dependency":
        symbolID_oper.setReadOnly(False)
        if Database.getSymbolValue("RNBD_Dependency_0","RN_HOST_UART_INST_FUNCTIONAL_USE") == "BLE USART INTERFACE" and localComponent.getID() == 'RNBD_Dependency_0':
            args.update({"eventID":"BLE_INTERFACE","sercomInstID":str(remoteID),"Connected": False})
            Database.sendMessage("RNBD_Dependency","SERCOM_INST_UPDATE",args)
        elif Database.getSymbolValue("RNBD_Dependency_1","RN_HOST_UART_INST_FUNCTIONAL_USE") == "TRANSPARENT UART EXAMPLE" and localComponent.getID() == 'RNBD_Dependency_1':
            args.update({"eventID":"TRANSPARENT_UART_INTERFACE","sercomInstID":str(remoteID),"Connected": False})
            Database.sendMessage("RNBD_Dependency","SERCOM_INST_UPDATE",args)


def instantiateComponent(rnHostLib,index):
    #Log.writeInfoMessage("Initiating RN HOST LIBRARY")
    #print("rnHostLib",rnHostLib.getID())
    configName = Variables.get("__CONFIGURATION_NAME")
    #print configName
    processor = Variables.get("__PROCESSOR")
    #print processor
    global InstIndex
    InstIndex = index
    global rnHostUartInstFuncUse
    
    #rnHostLib.setDependencyEnabled("RNBD_USART_Dependency",True)
    #components = Database.getActiveComponentIDs()

    #rnHostLib.setDependencyEnabled("Delay_Service_Dependency",True)
    #components = Database.getActiveComponentIDs()
        
    #rnHostLibobjects.update({"rnComponent":rnHostLib})
    
    # RN Host Lib configuration options
    rnHostUartInst  = rnHostLib.createIntegerSymbol("RN_HOST_UART_INST_INDEX",None)
    rnHostUartInst.setVisible(False)
    rnHostUartInst.setDefaultValue(index)
    
    # RN Host Lib configuration options
    rnHostUartInst  = rnHostLib.createStringSymbol("RN_HOST_UART_INST_USED",None)
    rnHostUartInst.setLabel("UART INSTANCE")
    rnHostUartInst.setReadOnly(True)
    rnHostUartInst.setDefaultValue("")
    
    #Functioanlity symbol:
    rnHostUartInstFuncUse  = rnHostLib.createStringSymbol("RN_HOST_UART_INST_FUNCTIONAL_USE",None)
    rnHostUartInstFuncUse.setLabel("DEPENDENCY")
    rnHostUartInstFuncUse.setReadOnly(True)
    
    if InstIndex == 0: 
        rnHostUartInstFuncUse.setDefaultValue("BLE USART INTERFACE")

    
    
    
    
def finalizeComponent(rnHostLib):
    #print("finalizeComponent")
    if Database.getSymbolValue("RNBD_Dependency","RN_HOST_EXAMPLE_APPLICATION_CHOICE") == "TRANSPARENT UART":
        Database.setSymbolValue("RNBD_Dependency_1","RN_HOST_UART_INST_FUNCTIONAL_USE","TRANSPARENT UART EXAMPLE")

    
def destroyComponent(rnHostLib) :
    symbolID_oper.setReadOnly(False)
    #print("rnHostDestroyComponent")
     
    