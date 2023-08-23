# coding: utf-8
##############################################################################
# Copyright (C) 2019-2023 Microchip Technology Inc. and its subsidiaries.
#
# Subject to your compliance with these terms, you may use Microchip software
# and any derivatives exclusively with Microchip products. It is your
# responsibility to comply with third party license terms applicable to your
# use of third party software (including open source software) that may
# accompany Microchip software.
#
# THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
# WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
# PARTICULAR PURPOSE.
#
# IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
# INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
# WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
# BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
# FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
# ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
# THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
##############################################################################

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
                 'DelayServiceInst':'',
                 'ConsoleSercomInst':''}   
global ModuleType
ModuleType = "RNBD" 

global RNBD_IS_NON_SECURE
RNBD_IS_NON_SECURE = True

RNBD_TrustZone_Variables = { 'RNBD_NON_SECURE' : True,
                        'BLE_SERCOM_NON_SECURE' : False,
                        'CONSOLE_SERCOM_NON_SECURE' : False,
                        'RNBD_SECURE_API_GEN_CHECK' : False,
                        'TRUST_ZONE_FILE_GEN_CHECK' : False}

RNBD_Pin_Configuration = {'BT_RST':{'Pin':'',
                                    'Name':'BT_RST',
                                    'Dir':'',
                                    'update':False},
                        'BT_STATUS1':{'Pin':'',
                                    'Name':'BT_STATUS1',
                                    'Dir':'',
                                    'update':False},
                        'BT_STATUS2':{'Pin':'',
                                    'Name':'BT_STATUS2',
                                    'Dir':'',
                                    'update':False},
                        'BT_RX_IND':{'Pin':'',
                                    'Name':'BT_RX_IND',
                                    'Dir':'',
                                    'update':False},
                        'BT_MODE':{'Pin':'',
                                    'Name':'BT_MODE',
                                    'Dir':'',
                                    'update':False},
                        
                        }

global rst_pin_config_msg
rst_pin_config_msg = "**Set the pin functionality as *GPIO*, Pin name as *BT_RST*, Direction as *Out* inside Pin Configuration**"
global status_pin1_config_msg
status_pin1_config_msg = "**Set the pin functionality as *GPIO*, Pin name as *BT_STATUS1**"
global status_pin2_config_msg
status_pin2_config_msg = "**Set the pin functionality as *GPIO*, Pin name as *BT_STATUS2**"
global rx_ind_Pin_config_msg
rx_ind_Pin_config_msg = "**Set the pin functionality as *GPIO*, Pin name as *BT_RX_IND*, Direction as *Out* inside Pin Configuration**"
global sys_mode_Pin_config_msg
sys_mode_Pin_config_msg = "**Set the pin functionality as *GPIO*, Pin name as *BT_MODE*, Direction as *Out* inside Pin Configuration**"



global rst_pin_dir_config_msg
rst_pin_dir_config_msg = "Set Pin direction as *Out* inside Pin configuration"
global status_pin1_dir_config_msg
status_pin1_dir_config_msg = "Set Pin direction as *In* inside Pin configuration"
global status_pin2_dir_config_msg
status_pin2_dir_config_msg = "Set Pin direction as *In* inside Pin configuration"

global BTPinSecureMsg
BTPinSecureMsg = "**Set Module Pins as Secure inside Pin Configuration**"

global BTPinNonSecureMsg
BTPinNonSecureMsg = "**Set Module Pins as Non Secure inside Pin Configuration**"
              
         
def handleMessage(messageID, args):
    #print("HanldeMessage",messageID,args)    
    if messageID == "SERCOM_INST_UPDATE":
        if args["eventID"] == "BLE_INTERFACE":
            if args["Connected"] == True:
                ConnectedInst.update({'InterfaceSercomInst':str(args["sercomInstID"])})
                if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
                    RNBD_TrustZone_Variables.update({"BLE_SERCOM_NON_SECURE" : Database.getSymbolValue("core", ConnectedInst['InterfaceSercomInst'].upper() + "_IS_NON_SECURE")})
                    updateInterfaceSercomMarkupVariable()
                updateSercomInstMarkupVaribles("SERCOM_INST",str(args["sercomInstID"]).upper())
                non_secure_entry_File_check()

            elif args["Connected"] == False:
                ConnectedInst.update({'InterfaceSercomInst':''})
                #rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INST",NULL)
                RNBD_TrustZone_Variables.update({"BLE_SERCOM_NON_SECURE" : False})
                updateSercomInstMarkupVaribles("SERCOM_INST",'')
                if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
                    updateInterfaceSercomMarkupVariable()


        elif args["eventID"] == "TRANSPARENT_UART_INTERFACE":
            if args["Connected"] == True:
                ConnectedInst.update({'ConsoleSercomInst':str(args["sercomInstID"])})
                if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
                    RNBD_TrustZone_Variables.update({"CONSOLE_SERCOM_NON_SECURE" : Database.getSymbolValue("core", ConnectedInst['ConsoleSercomInst'].upper() + "_IS_NON_SECURE")})
                    updateConsoleSercomMarkupVariable()
                updateSercomInstMarkupVaribles("CONSOLE_SERCOM_INST",str(args["sercomInstID"]).upper())
                non_secure_entry_File_check()
            elif args["Connected"] == False:
                ConnectedInst.update({'ConsoleSercomInst':''})
                RNBD_TrustZone_Variables.update({"CONSOLE_SERCOM_NON_SECURE" : False})
                updateSercomInstMarkupVaribles("CONSOLE_SERCOM_INST",'')
                if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
                    updateConsoleSercomMarkupVariable()

#######################################################################################################################
##                      Connected Sercom dependencies Markup Variable update
#######################################################################################################################
def updateSercomInstMarkupVaribles(Markup_Variable, Value):
    for i in range(len(rnHostLibFilesArray)):
        rnHostLibFilesArray[i].addMarkupVariable(str(Markup_Variable).upper(),str(Value).upper())
    if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
        rnbdTrustZoneFiles[0].addMarkupVariable(str(Markup_Variable).upper(),str(Value).upper())
        rnbdTrustZoneFiles[1].addMarkupVariable(str(Markup_Variable).upper(),str(Value).upper()) 

#######################################################################################################################
#                                  Application File Gneration Callbacks
#######################################################################################################################
def EnableTrpUartAppDependencies():
    components = Database.getActiveComponentIDs()
    args = {"Application Type": "TRANSPARENT UART","Enable":True}
    components = Database.getActiveComponentIDs()
    if 'RNBD_Dependency_1' not in components:
        Database.activateComponents(["RNBD_Dependency"])
    Database.sendMessage("RNBD_Dependency_1","Application_Selection_Update",args)
      
def DisableTrpUartAppDependencies():
    components = Database.getActiveComponentIDs()
    args = {"Application Type": "TRANSPARENT UART","Enable":False}
    components = Database.getActiveComponentIDs()
    if 'RNBD_Dependency_1' in components:
        success = Database.deactivateComponents(["RNBD_Dependency_1"])
        #print("success",success)

def rnHostTrpUartExpAppSourceCallback(rnExampleTrpUartAppSourceFile,event):
    global ApplicationType
    if event["id"] == "RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE":
        if event["value"] == "RNBD":
            rnExampleTrpUartAppSourceFile.setOutputName("rnbd_example.c")    
        elif event["value"] == "RN487x":
            rnExampleTrpUartAppSourceFile.setOutputName("rn487x_example.c")
        ModuleType = str(event["value"])
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
        
    elif event["id"] == "RN_HOST_EXAMPLE_APPLICATION_CHOICE":
        if(event["value"] == "TRANSPARENT UART"):
            rnExampleTrpUartAppSourceFile.setEnabled(True)
            EnableTrpUartAppDependencies()
        else:
            rnExampleTrpUartAppSourceFile.setEnabled(False)
            DisableTrpUartAppDependencies()
        
        ApplicationType = str(event["value"]).upper()
        
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            non_secure_entry_File_check()
        
def rnHostTrpUartExpAppHeaderCallback(rnExampleTrpUartAppHeaderFile,event):
    if event["id"] == "RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE":
        if event["value"] == "RNBD":
            rnExampleTrpUartAppHeaderFile.setOutputName("rnbd_example.h")
        elif event["value"] == "RN487x":
            rnExampleTrpUartAppHeaderFile.setOutputName("rn487x_example.h")
        ModuleType = event["value"]    
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            
    elif event["id"] == "RN_HOST_EXAMPLE_APPLICATION_CHOICE":
        if(event["value"] == "TRANSPARENT UART"):
            rnExampleTrpUartAppHeaderFile.setEnabled(True)
        else:
            rnExampleTrpUartAppHeaderFile.setEnabled(False)
            
        ApplicationType = str(event["value"]).upper()
        
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            non_secure_entry_File_check()
        
def rnHostBasicDataExcExpAppSourceCallback(rnExampleBscDataExcAppSourceFile,event):
    if event["id"] == "RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE":
        if event["value"] == "RNBD":
            rnExampleBscDataExcAppSourceFile.setOutputName("rnbd_example.c")
        elif event["value"] == "RN487x":
            rnExampleBscDataExcAppSourceFile.setOutputName("rn487x_example.c")
        ModuleType = event["value"]
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            
    elif event["id"] == "RN_HOST_EXAMPLE_APPLICATION_CHOICE":
        if(event["value"] == "BASIC DATA EXCHANGE"):
            rnExampleBscDataExcAppSourceFile.setEnabled(True)
        else:
            rnExampleBscDataExcAppSourceFile.setEnabled(False)
            
        ApplicationType = str(event["value"]).upper()    
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            non_secure_entry_File_check()
        
def rnHostBasicDataExcExpAppHeaderCallback(rnExampleBscDataExcAppHeaderFile,event):
    if event["id"] == "RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE":
        if event["value"] == "RNBD":
            rnExampleBscDataExcAppHeaderFile.setOutputName("rnbd_example.h")
        elif event["value"] == "RN487x":
            rnExampleBscDataExcAppHeaderFile.setOutputName("rn487x_example.h")
        ModuleType = event["value"]    
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setDestPath("../../trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[1].setProjectPath("trustZone/"+ event["value"].lower()+'/')
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_MODULE_SELECTION",str(event["value"]))
        
    elif event["id"] == "RN_HOST_EXAMPLE_APPLICATION_CHOICE":
        if(event["value"] == "BASIC DATA EXCHANGE"):
            rnExampleBscDataExcAppHeaderFile.setEnabled(True)
        else:
            rnExampleBscDataExcAppHeaderFile.setEnabled(False)
            
        ApplicationType = str(event["value"]).upper()
        if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
            rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_EXAMPLE_SELECTION",event['value'])
            non_secure_entry_File_check()
        
##########################################################################################
#                           Interface File Generation Handling Callbacks
##########################################################################################
def rn487xBLEInterfaceSourceCallback(rn487xBLEInterfaceSourceFile,event):
    if(event["value"] == "RN487x"):
        rn487xBLEInterfaceSourceFile.setEnabled(True)
    else:
        rn487xBLEInterfaceSourceFile.setEnabled(False)
        
def rn487xBLEInterfaceHeaderCallback(rn487xBLEInterfaceHeaderFile,event):
    if(event["value"] == "RN487x"):
        rn487xBLEInterfaceHeaderFile.setEnabled(True)
    else:
        rn487xBLEInterfaceHeaderFile.setEnabled(False)
        
def rn487xBLEFeatureSourceCallback(rn487xBLEFeatureSourceFile,event):
    if(event["value"] == "RN487x"):
        rn487xBLEFeatureSourceFile.setEnabled(True)
    else:
        rn487xBLEFeatureSourceFile.setEnabled(False)

def rn487xBLEFeatureHeaderCallback(rn487xBLEFeatureHeaderFile,event):
    if(event["value"] == "RN487x"):
        rn487xBLEFeatureHeaderFile.setEnabled(True)
    else:
        rn487xBLEFeatureHeaderFile.setEnabled(False)
        
def rnbdBLEInterfaceSourceCallback(rnbdBLEInterfaceSourceFile,event):
    if(event["value"] == "RNBD"):
        rnbdBLEInterfaceSourceFile.setEnabled(True)
    else:
        rnbdBLEInterfaceSourceFile.setEnabled(False)

def rnbdBLEInterfaceHeaderCallback(rnbdBLEInterfaceHeaderFile,event):
    if(event["value"] == "RNBD"):
        rnbdBLEInterfaceHeaderFile.setEnabled(True)
    else:
        rnbdBLEInterfaceHeaderFile.setEnabled(False)
        
def rnbdBLEFeatureSourceCallback(rnbdBLEFeatureSourceFile,event):
    if(event["value"] == "RNBD"):
        rnbdBLEFeatureSourceFile.setEnabled(True)
    else:
        rnbdBLEFeatureSourceFile.setEnabled(False)
        
def rnbdBLEFeatureHeaderCallback(rnbdBLEFeatureHeaderFile,event):
    if(event["value"] == "RNBD"):
        rnbdBLEFeatureHeaderFile.setEnabled(True)
    else:
        rnbdBLEFeatureHeaderFile.setEnabled(False)
        
###############################################################################################################
#                                   Trust Zone support Callbacks
###############################################################################################################
def Sercom_Instances_Get():
    SercomInstance = 0
    periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
    modules = periphNode.getChildren()
    if modules != None:
        for module in range (0, len(modules)):
            instances = modules[module].getChildren()
            for instance in range (0, len(instances)):
                periphInstance = str(instances[instance].getAttribute("name"))
                periphInstanceName.append(periphInstance)
                if 'SERCOM' in periphInstance:
                    SercomInstance+=1
        SercomInstanceValue = SercomInstance       
    #print("*%*%*%%****",periphInstanceName,SercomInstanceValue)
    return SercomInstanceValue 

#######################################################################################
## GPIO Read
#######################################################################################
import re

def sort_alphanumeric(l):
    convert = lambda text: int(text) if text.isdigit() else text.lower()
    alphanum_key = lambda key: [ convert(c) for c in re.split('([0-9]+)', key) ]
    return sorted(l, key = alphanum_key)

def get_port_pin_dependencies():
    global pin_map_internal
    global portPackage
    pin_map_internal = {}
    package = {}
    global gpio_dependency
    gpio_dependency = []
    global gpio_attr_sym
    gpio_attr_sym = {}
    global gpio_attr_update
    gpio_attr_update = {}
    global pin_map
    pin_map = {}
    # Build package pinout map
    packageNode = ATDF.getNode("/avr-tools-device-file/variants")
    for id in range(0,len(packageNode.getChildren())):
        package[packageNode.getChildren()[id].getAttribute("package")] = packageNode.getChildren()[id].getAttribute("pinout")

    ## Find Number of unique pinouts
    uniquePinout = len(set(package.values()))
    #print('uniquePinout:',uniquePinout)
    ## get the pin count
    pincount = int(re.findall(r'\d+', package.keys()[0])[0])
    max_index = Database.getSymbolValue("core","PORT_PIN_MAX_INDEX")
    #print('max_index:',max_index)
    # Create portGroupName list of uppercase letters
    global portGroupName
    portGroupName = []
    for letter in range(65,91):
        portGroupName.append(chr(letter))
    
    portPackage =  Database.getSymbolValue("core","COMPONENT_PACKAGE")

    pinoutNode = ATDF.getNode('/avr-tools-device-file/pinouts/pinout@[name= "' + str(package.get(portPackage)) + '"]')
    for id in range(0,len(pinoutNode.getChildren())):
        if pinoutNode.getChildren()[id].getAttribute("type") == None:
            if "BGA" in portPackage or "WLCSP" in portPackage or "DRQFN" in portPackage:
                pin_map[pinoutNode.getChildren()[id].getAttribute("position")] = pinoutNode.getChildren()[id].getAttribute("pad")
            else:
                pin_map[int(pinoutNode.getChildren()[id].getAttribute("position"))] = pinoutNode.getChildren()[id].getAttribute("pad")
        else:
            pin_map_internal[pinoutNode.getChildren()[id].getAttribute("type").split("INTERNAL_")[1]] = pinoutNode.getChildren()[id].getAttribute("pad")

    if "BGA" in portPackage or "WLCSP" in portPackage or "DRQFN" in portPackage:
        pin_position = sort_alphanumeric(pin_map.keys())
        pin_position_internal = sort_alphanumeric(pin_map_internal.keys())
    else:
        pin_position = sorted(pin_map.keys())
        pin_position_internal = sorted(pin_map_internal.keys())

    internalPincount = pincount + len(pin_map_internal.keys())

    global pin_num_ID_map
    pin_num_ID_map = {}
    global pin_IDS
    pin_IDS = []
    for pinNumber in range(1, internalPincount + 1):
        gpio_local = {}
        if pinNumber < pincount + 1:
            gpio_attr_sym[str(pinNumber)] = ["core."+"PORT_PIN"+str(pinNumber),"core."+"PIN_" + str(pinNumber) + "_PORT_PIN", "core."+"PIN_" + str(pinNumber) + "_PORT_GROUP","core."+"PIN_" + str(pinNumber) + "_FUNCTION_NAME","core."+"PIN_" + str(pinNumber) + "_PERIPHERAL_FUNCTION","core."+"PIN_" + str(pinNumber) + "_INEN"]
            gpio_local['Pin_num'] = Database.getSymbolValue('core',"PORT_PIN"+str(pinNumber))
            gpio_local['Bit_Pos'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PORT_PIN")
            gpio_local['Group']   = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PORT_GROUP")
            gpio_local['Name'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_FUNCTION_NAME")
            gpio_local['Pin_Func'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PERIPHERAL_FUNCTION")
            gpio_local['Dir'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_DIR")
            gpio_local['INEN'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_INEN")
            gpio_attr_update[str(pinNumber)] = gpio_local
            if str(gpio_attr_update[str(pinNumber)]['Bit_Pos']) != '0':
                pin_num_ID_map[pinNumber] = str('P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos']))
                #pin_IDS.append(str('P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])))
            for attr in range(len(gpio_attr_sym[str(pinNumber)])):
                gpio_dependency.append(gpio_attr_sym[str(pinNumber)][attr])
            #if gpio_local['Name'] == 'BT_RST':
                #print('Updating Reset Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Reset Pin Updated:',RNBD_Pin_Configuration[str('BT_RST')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_RST')].update({'update':True})
            #if gpio_local['Name'] == 'BT_STATUS1':
                #print('Updating Status 1 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-1 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS1')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_STATUS1')].update({'update':True})
            #if gpio_local['Name'] == 'BT_STATUS2':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_STATUS2')].update({'update':True})
            #if gpio_local['Name'] == 'BT_RX_IND':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_RX_IND')].update({'update':True})
            #if gpio_local['Name'] == 'BT_MODE':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_MODE')].update({'update':True})
            check_Assigned_GPIO_Functionality(gpio_local['Name'],pinNumber)

        else:
            gpio_attr_sym[str(pinNumber)] = ["core."+"PORT_PIN"+str(pinNumber),"core."+"PIN_" + str(pinNumber) + "_PORT_PIN", "core."+"PIN_" + str(pinNumber) + "_PORT_GROUP","core."+"PIN_" + str(pinNumber) + "_FUNCTION_NAME","core."+"PIN_" + str(pinNumber) + "_PERIPHERAL_FUNCTION","core."+"PIN_" + str(pinNumber) + "_DIR","core."+"PIN_" + str(pinNumber) + "_INEN"]
            gpio_local['Pin_num'] = Database.getSymbolValue('core',"PORT_PIN"+str(pinNumber))
            gpio_local['Bit_Pos'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PORT_PIN")
            gpio_local['Group']   = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PORT_GROUP")
            gpio_local['Name'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_FUNCTION_NAME")
            gpio_local['Pin_Func'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_PERIPHERAL_FUNCTION")
            gpio_local['Dir'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_DIR")
            gpio_local['INEN'] = Database.getSymbolValue('core',"PIN_" + str(pinNumber) + "_INEN")
            gpio_attr_update[str(pinNumber)] = gpio_local
            if str(gpio_attr_update[str(pinNumber)]['Bit_Pos']) != '0':
                pin_num_ID_map[pinNumber] = str('P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos']))
                #pin_IDS.append(str('P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])))
            for attr in range(len(gpio_attr_sym[str(pinNumber)])):
                gpio_dependency.append(gpio_attr_sym[str(pinNumber)][attr])
            check_Assigned_GPIO_Functionality(gpio_local['Name'],pinNumber)
            #if gpio_local['Name'] == 'BT_RST':
                #print('Updating Variable')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
            #    RNBD_Pin_Configuration[str('BT_RST')].update({'update':True})
            #if gpio_local['Name'] == 'BT_STATUS1':
                #print('Updating Status 1 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-1 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS1')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_STATUS1')].update({'update':True})
            #if gpio_local['Name'] == 'BT_STATUS2':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_STATUS2')].update({'update':True})
            #if gpio_local['Name'] == 'BT_RX_IND':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_RX_IND')].update({'update':True})
            #if gpio_local['Name'] == 'BT_MODE':
                #print('Updating Status 2 Pin Details')
            #    RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
                #print('RNBD Status-2 Pin Updated:',RNBD_Pin_Configuration[str('BT_STATUS2')]['Pin'])
            #    RNBD_Pin_Configuration[str('BT_MODE')].update({'update':True})

    #pin_IDS.insert(0,'')
    #print('pin_IDS',pin_IDS)
    #print('gpio_attr_update',gpio_attr_update)
    #print('pin_num_ID_map',pin_num_ID_map)

def check_Assigned_GPIO_Functionality(GPIO_Name,pinNumber):
    if GPIO_Name == 'BT_RST':
        RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
        RNBD_Pin_Configuration[str('BT_RST')].update({'update':True})
    if GPIO_Name == 'BT_STATUS1':
        RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
        RNBD_Pin_Configuration[str('BT_STATUS1')].update({'update':True})
    if GPIO_Name == 'BT_STATUS2':
        RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
        RNBD_Pin_Configuration[str('BT_STATUS2')].update({'update':True})
    if GPIO_Name == 'BT_RX_IND':
        RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
        RNBD_Pin_Configuration[str('BT_RX_IND')].update({'update':True})
    if GPIO_Name == 'BT_MODE':
        RNBD_Pin_Configuration[str(gpio_attr_update[str(pinNumber)]['Name'])].update({'Pin': 'P'+str(gpio_attr_update[str(pinNumber)]['Group'])+ str(gpio_attr_update[str(pinNumber)]['Bit_Pos'])})
        RNBD_Pin_Configuration[str('BT_MODE')].update({'update':True})


def GPIO_Update_Callback(symbol,event):
    print('GPIO callback Triggered')
    #print(symbol,event)
    sym_ID = symbol.getID()
    #print('sym_ID',sym_ID)

    #print('event_val:',event['value'])

    pin_num = (re.findall(r'\d+', event['id']))[0]
    if 'PERIPHERAL_FUNCTION' in event['id']:
        gpio_attr_update[str(pin_num)].update({'Pin_Func' : str(event['value'])})
        if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_RST"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] != 'GPIO':
            RNBD_Pin_Configuration["BT_RST"].update({'Pin':''})
            #rnHostRstPinMsg.setLabel(rst_pin_config_msg)
            rnHostRstPin.setValue('')
            #rnHostRstPinMsg.setVisible(True)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_RST_Pin_Selected",False)

        if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_STATUS1"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] != 'GPIO':
            RNBD_Pin_Configuration["BT_STATUS1"].update({'Pin':''})
            if rnHostStatusPinCheck.getValue() == True:
                rnHostStatusPin1.setValue('')
                #rnHostStatusPin1Msg.setLabel(status_pin1_config_msg)
                #rnHostStatusPin1Msg.setVisible(True)
            else:
                RNBD_Pin_Configuration["BT_STATUS1"].update({'update':True})
        
        if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_STATUS2"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] != 'GPIO':
            RNBD_Pin_Configuration["BT_STATUS2"].update({'Pin':''})
            if rnHostStatusPinCheck.getValue() == True:
                rnHostStatusPin2.setValue('')
                #rnHostStatusPin2Msg.setLabel(status_pin2_config_msg)
                #rnHostStatusPin2Msg.setVisible(True)
            else:
                RNBD_Pin_Configuration["BT_STATUS2"].update({'update':True})

        if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_RX_IND"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] != 'GPIO':
            RNBD_Pin_Configuration["BT_RX_IND"].update({'Pin':''})
            if rnHostRxIndPinCheck.getValue() == True:
                rnHostRxIndPinSelected.setValue('')
                #rnHostStatusPin2Msg.setLabel(status_pin2_config_msg)
                #rnHostStatusPin2Msg.setVisible(True)
            else:
                RNBD_Pin_Configuration["BT_RX_IND"].update({'update':True})

        if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_MODE"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] != 'GPIO':
            RNBD_Pin_Configuration["BT_MODE"].update({'Pin':''})
            if rnHostSystemModePinCheck.getValue() == True:
                rnHostSystemModePinSelected.setValue('')
                #rnHostStatusPin2Msg.setLabel(status_pin2_config_msg)
                #rnHostStatusPin2Msg.setVisible(True)
            else:
                RNBD_Pin_Configuration["BT_MODE"].update({'update':True})

    elif 'FUNCTION_NAME' in event['id']:
        gpio_attr_update[str(pin_num)].update({'Name' : str(event['value'])})
        if  str(event['value']) == 'BT_RST' and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO':
            #print('Updating Variable')
            RNBD_Pin_Configuration["BT_RST"].update({'Pin':'P'+ str(gpio_attr_update[str(pin_num)]['Group'])+str(gpio_attr_update[str(pin_num)]['Bit_Pos'])})
            rnHostRstPin.setValue(RNBD_Pin_Configuration[str(event['value'])]['Pin'])
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_RST_Pin_Selected",True)
            #rnHostRstPinMsg.setVisible(False)
            #Database.setSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req= str(RNBD_Pin_Configuration['BT_RST']['Pin']))) + "_FUNCTION_NAME" ,'bt_rst') 
            #print('Pin name Updated')
            #check_gpio_dir()

        if str(event['value']) == 'BT_STATUS1' and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO':
            #print('Updating Variable')
            RNBD_Pin_Configuration['BT_STATUS1'].update({'Pin':'P'+ str(gpio_attr_update[str(pin_num)]['Group'])+str(gpio_attr_update[str(pin_num)]['Bit_Pos'])})
            if rnHostStatusPinCheck.getValue() == True:
                rnHostStatusPin1.setValue(RNBD_Pin_Configuration[str(event['value'])]['Pin'])
                #rnHostStatusPin1Msg.setVisible(False)
                #check_gpio_dir()
            else:
                RNBD_Pin_Configuration["BT_STATUS1"].update({'update':True})

        if str(event['value']) == 'BT_STATUS2' and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO':
            #print('Updating Variable')
            RNBD_Pin_Configuration['BT_STATUS2'].update({'Pin':'P'+ str(gpio_attr_update[str(pin_num)]['Group'])+str(gpio_attr_update[str(pin_num)]['Bit_Pos'])})
            if rnHostStatusPinCheck.getValue() == True:
                rnHostStatusPin2.setValue(RNBD_Pin_Configuration[str(event['value'])]['Pin'])
                #rnHostStatusPin2Msg.setVisible(False)
                #check_gpio_dir()
            else:
                 RNBD_Pin_Configuration["BT_STATUS2"].update({'update':True})
        
        if str(event['value']) == 'BT_RX_IND' and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO':
            #print('Updating Variable')
            RNBD_Pin_Configuration['BT_RX_IND'].update({'Pin':'P'+ str(gpio_attr_update[str(pin_num)]['Group'])+str(gpio_attr_update[str(pin_num)]['Bit_Pos'])})
            if rnHostRxIndPinCheck.getValue() == True:
                rnHostRxIndPinSelected.setValue(RNBD_Pin_Configuration[str(event['value'])]['Pin'])
                #rnHostStatusPin2Msg.setVisible(False)
                #check_gpio_dir()
            else:
                 RNBD_Pin_Configuration["BT_RX_IND"].update({'update':True})

        if str(event['value']) == 'BT_MODE' and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO':
            #print('Updating Variable')
            RNBD_Pin_Configuration['BT_MODE'].update({'Pin':'P'+ str(gpio_attr_update[str(pin_num)]['Group'])+str(gpio_attr_update[str(pin_num)]['Bit_Pos'])})
            if rnHostSystemModePinCheck.getValue() == True:
                rnHostSystemModePinSelected.setValue(RNBD_Pin_Configuration[str(event['value'])]['Pin'])
                #rnHostStatusPin2Msg.setVisible(False)
                #check_gpio_dir()
            else:
                 RNBD_Pin_Configuration["BT_MODE"].update({'update':True})

    #elif 'DIR' or 'INEN' in event['id']:
        #gpio_attr_update[str(pin_num)].update({'Dir' : str(event['value'])})
       # print('Direction Update')
        
        #if  'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_RST"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO' and  str(gpio_attr_update[str(pin_num)]['Name']) == 'BT_RST' :
        #    if check_gpio_dir() != True:
        #        rnHostRstPinMsg.setVisible(False)
                #RNBD_Pin_Configuration["BT_RST"].update({'Dir',str('Out')})

        #if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_STATUS1"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO' and  str(gpio_attr_update[str(pin_num)]['Name']) == 'BT_STATUS1' :
            #if rnHostStatusPinCheck.getValue() == True:
        #    if check_gpio_dir() != True:
        #        rnHostStatusPin1Msg.setVisible(False)
                #RNBD_Pin_Configuration["BT_STATUS1"].update({'Dir',str('In')})
            
        #if 'P' + str(gpio_attr_update[str(pin_num)]['Group']) + str(gpio_attr_update[str(pin_num)]['Bit_Pos']) == RNBD_Pin_Configuration["BT_STATUS2"]['Pin'] and gpio_attr_update[str(pin_num)]['Pin_Func'] == 'GPIO' and  str(gpio_attr_update[str(pin_num)]['Name']) == 'BT_STATUS2' :
            #if rnHostStatusPinCheck.getValue() == True:
        #    if check_gpio_dir() != True:
        #        rnHostStatusPin2Msg.setVisible(False)
                #RNBD_Pin_Configuration["BT_STATUS2"].update({'Dir',str('In')})
                
    

def BT_Pin_Functionality_Update(symbol,event):
    print('BT_Status_Pin_Functionality_Update',symbol,event)
    if event['id'] == 'BT_STATUS_PIN_CHECK':
        if event['value'] == True:
            rnHostStatusPin1.setVisible(True)
            rnHostStatusPin2.setVisible(True)
            rnHostStatusPin1Msg.setVisible(True)
            rnHostStatusPin2Msg.setVisible(True)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_STATUS_PIN_CHECK_ENABLE",True)
            check_update_pins()
        elif event['value'] == False:
            rnHostStatusPin1.setVisible(False)
            rnHostStatusPin2.setVisible(False)
            rnHostStatusPin1Msg.setVisible(False)
            rnHostStatusPin2Msg.setVisible(False)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_STATUS_PIN_CHECK_ENABLE",False)
            RNBD_Pin_Configuration[str('BT_STATUS1')].update({'update':True})
            RNBD_Pin_Configuration[str('BT_STATUS2')].update({'update':True})
    
    if event['id'] == 'BT_RX_IND_PIN_CHECK':
        if event['value'] == True:
            rnHostRxIndPinSelected.setVisible(True)
            rnHostRxIndPinMsg.setVisible(True)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_RX_IND_PIN_CHECK_ENABLE",True)
            check_update_pins()
        elif event['value'] == False:
            rnHostRxIndPinSelected.setVisible(False)
            rnHostRxIndPinMsg.setVisible(False)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_RX_IND_PIN_CHECK_ENABLE",False)
            RNBD_Pin_Configuration[str('BT_RX_IND')].update({'update':True})


    if event['id'] == 'BT_SYS_MODE_PIN_CHECK':
        if event['value'] == True:
            rnHostSystemModePinSelected.setVisible(True)
            rnHostSysModePinMsg.setVisible(True)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_SYS_MODE_PIN_CHECK_ENABLE",True)
            check_update_pins()
        elif event['value'] == False:
            rnHostSystemModePinSelected.setVisible(False)
            rnHostSysModePinMsg.setVisible(False)
            for i in range(len(rnHostLibFilesArray)):
                rnHostLibFilesArray[i].addMarkupVariable("BT_SYS_MODE_PIN_CHECK_ENABLE",False)
            RNBD_Pin_Configuration[str('BT_MODE')].update({'update':True})

def check_gpio_dir():
    #print('Check GPIO DIR')
    reset_pin_flag = False
    status1_flag = False
    status2_flag = False

    if RNBD_Pin_Configuration['BT_RST']['Pin'] != '':
        reset_pin_dir = str(Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_RST']['Pin']))) + "_DIR"))
        reset_pin_inen = str(Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_RST']['Pin']))) + "_INEN"))
        #print('reset_pin_dir',reset_pin_dir)
        #print('reset_pin_inen',reset_pin_inen)
        if (reset_pin_dir == '') or (reset_pin_inen == 'True'):
            rnHostRstPinMsg.setLabel(rst_pin_dir_config_msg)
            rnHostRstPinMsg.setVisible(True)
            reset_pin_flag = True

    #if rnHostStatusPinCheck.getValue() == True:
    if RNBD_Pin_Configuration['BT_STATUS1']['Pin'] != '':
        #print('BT_STATUS1_Pin',RNBD_Pin_Configuration['BT_STATUS1']['Pin'] )
        #print('BT_STATUS1_Pin',str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))))
        status1_pin_dir = Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))) + "_DIR")
        status1_pin_inen = Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))) + "_INEN")
        #print('status1_pin_dir',status1_pin_dir)
        #print('status1_pin_inen',status1_pin_inen)
        if (status1_pin_dir == 'Out') or (status1_pin_inen == '') :
            #Database.setSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req= str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))) + "_DIR" ," ") 
            rnHostStatusPin1Msg.setLabel(status_pin1_dir_config_msg)
            rnHostStatusPin1Msg.setVisible(True)
            #print('BT_STATUS_PIN_DIR-1',str(Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req= str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))) + "_DIR")).upper())
            status1_flag = True

    if RNBD_Pin_Configuration['BT_STATUS2']['Pin'] != '':
        status2_pin_dir = str(Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_STATUS2']['Pin']))) + "_DIR"))
        status2_pin_inen = str(Database.getSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req=str(RNBD_Pin_Configuration['BT_STATUS2']['Pin']))) + "_INEN"))
        #print('status2_pin_dir',status2_pin_dir)
        #print('status2_pin_inen',status2_pin_inen)
        if (status2_pin_dir == 'Out') or (status2_pin_inen == ''):
            #Database.setSymbolValue('core','PIN_'+ str(extract_pin_num_ID(pin_ID_req= str(RNBD_Pin_Configuration['BT_STATUS2']['Pin']))) + "_DIR" ,'In') 
            rnHostStatusPin2Msg.setLabel(status_pin2_dir_config_msg)
            rnHostStatusPin2Msg.setVisible(True)
            status2_flag = True
    
    if reset_pin_flag or status1_flag or status2_flag == True:
        return True
    else:
        return False


def check_update_pins():
    print('check_update_pins')
    if RNBD_Pin_Configuration['BT_RST']['update'] == True:
        #print('Updating Variable')
        rnHostRstPin.setValue(str(RNBD_Pin_Configuration['BT_RST']['Pin']))
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("BT_RST_Pin_Selected",True)
        #rnHostRstPinMsg.setVisible(False)
        RNBD_Pin_Configuration[str('BT_RST')].update({'update':False})

    if RNBD_Pin_Configuration['BT_STATUS1']['update'] == True:
        if rnHostStatusPinCheck.getValue() == True: 
            #print('Updating Variable')
            rnHostStatusPin1.setValue(str(RNBD_Pin_Configuration['BT_STATUS1']['Pin']))
            #rnHostStatusPin1Msg.setVisible(False)
            RNBD_Pin_Configuration[str('BT_STATUS1')].update({'update':False})

    if RNBD_Pin_Configuration['BT_STATUS2']['update'] == True:
        if rnHostStatusPinCheck.getValue() == True:
            #print('Updating Variable')
            rnHostStatusPin2.setValue(str(RNBD_Pin_Configuration['BT_STATUS2']['Pin']))
            #rnHostStatusPin2Msg.setVisible(False)
            RNBD_Pin_Configuration[str('BT_STATUS2')].update({'update':False})

    print('BT_RX_IND_Pin',str(RNBD_Pin_Configuration['BT_RX_IND']['Pin']))
    if RNBD_Pin_Configuration['BT_RX_IND']['update'] == True:
        if rnHostRxIndPinCheck.getValue() == True:
            #print('Updating Variable')
            rnHostRxIndPinSelected.setValue(str(RNBD_Pin_Configuration['BT_RX_IND']['Pin']))
            #rnHostStatusPin2Msg.setVisible(False)
            RNBD_Pin_Configuration[str('BT_RX_IND')].update({'update':False})

    if RNBD_Pin_Configuration['BT_MODE']['update'] == True:
        if rnHostSystemModePinCheck.getValue() == True:
            #print('Updating Variable')
            rnHostSystemModePinSelected.setValue(str(RNBD_Pin_Configuration['BT_MODE']['Pin']))
            #rnHostStatusPin2Msg.setVisible(False)
            RNBD_Pin_Configuration[str('BT_MODE')].update({'update':False})

    #check_gpio_dir()

def extract_pin_num_ID(pin_num_req = '',pin_ID_req = '',req = 'PIN_NUM'):
    for pin_num, pin_ID in pin_num_ID_map.items():
        if req ==  'PIN_NUM':
            if pin_ID_req == pin_ID:
                return pin_num
        elif req == 'PIN_ID':
            if pin_num_req == pin_num:
                return pin_ID
def RNBDPinSelectionUpdatesCallback(symbol,event):
	value = event['value']
	if value == '':
		rnHostRstSet.setValue(False)
	else:
		rnHostRstSet.setValue(True)

######################################################################################


def Timer_Instances_Get():
    TimerInstance = 0
    RTCInstances = 0
    periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
    modules = periphNode.getChildren()
    for module in range (0, len(modules)):
        instances = modules[module].getChildren()
        for instance in range (0, len(instances)):
            periphInstance = str(instances[instance].getAttribute("name"))
            periphInstanceName.append(periphInstance)
            res = list(re.findall(r'(\w+?)(\d+)', periphInstance))
            if res != []:
               if 'TC' == str(res[0][0]).upper():
                   TimerInstance+=1
            if 'RTC' == periphInstance:
                RTCInstances+=1
    TimerInstanceValue = TimerInstance
    RTCInstanceValue =  RTCInstances      
    return TimerInstanceValue, RTCInstanceValue
    
def SecureAPIGenerationOptionUpdate(symbol,event):
    if event["value"] == True:
        symbol.setVisible(True)
        if symbol.getValue() == True : 
            RNBD_TrustZone_Variables.update({"RNBD_SECURE_API_GEN_CHECK" : True})
    elif event["value"] == False:
        RNBD_TrustZone_Variables.update({"RNBD_SECURE_API_GEN_CHECK" : False})
        symbol.setVisible(False)
    non_secure_entry_File_check()
    updateRNBDMarkupVariable()
            

def TrustZoneFileGenerationUpdate(symbol,event):    
    if event["id"] == "RN_SECURE_API_GENERATION":
        if event["value"] == True:
            RNBD_TrustZone_Variables.update({"RNBD_SECURE_API_GEN_CHECK" : True})
        elif event["value"] == False:
            RNBD_TrustZone_Variables.update({"RNBD_SECURE_API_GEN_CHECK" : False})
            
        non_secure_entry_File_check()
        updateRNBDMarkupVariable()

#####################################################################################################
##          Trust Zone Mark Up varibale updates
####################################################################################################
def updateRNBDMarkupVariable():
    rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_NON_SECURE_ENTRY",RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"])
    rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_NON_SECURE_ENTRY",RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"])
    rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_MODULE_SELECTION",ModuleType)
    rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_MODULE_SELECTION",ModuleType)
    #print('RNBD_NON_SECURE_ENTRY:',secureApiGenerationCheck)
    
    rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_NON_SECURE",RNBD_TrustZone_Variables["RNBD_NON_SECURE"])
    rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_NON_SECURE",RNBD_TrustZone_Variables["RNBD_NON_SECURE"])
    for i in range(len(rnHostLibFilesArray)):
        if RNBD_TrustZone_Variables["RNBD_NON_SECURE"] == True:
            rnHostLibFilesArray[i].setSecurity("NON_SECURE")
        else:
            rnHostLibFilesArray[i].setSecurity("SECURE")
        rnHostLibFilesArray[i].addMarkupVariable("RNBD_NON_SECURE",RNBD_TrustZone_Variables["RNBD_NON_SECURE"])    

## Update Interface Sercom Trust zone Markup variables
def updateInterfaceSercomMarkupVariable():
    if(ConnectedInst['InterfaceSercomInst'] != ''):
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
    else:
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",False)
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",False)
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",False)

## Update Console Sercom Trust zone Markup variables
def updateConsoleSercomMarkupVariable(console_sercom = 'default'):
    if(ConnectedInst['ConsoleSercomInst'] != ''):
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
    else:
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",False)
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",False)
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",False)

#############################################################################################
## Check RNBD non secure Entry Files To be generated 
#############################################################################################
def non_secure_entry_File_check():
    '''Possible combinations for non secure entry File generations - Enabled
    Case 1: RNBD is secure and non secure entry for RNBD API's are enabled
    Case 2: RNBD is secure and BLE sercom is non secure -- Error message generation
    Case 3: RNBD is secure and console sercom is non secure -- Error message generation

    Case 4: RNBD is non secure and BLE sercom is secure -- Non secure entry for BLE sercom API's
    Case 5: RNBD is non secure and console sercom is secure -- Non secure entry for Console sercom API's  
    
    Possible combinations for non secure entry File generations - Disabled

    Case 6: RNBD is non secure, BLE- connected, console-connected sercom are non secure -- Disable Trust Zone file generation
    Case 7: RNBD is non secure, BLE- connected or console-connected sercom are non secure -- Disable Trust Zone file generation
    Case 8: RNBD is non secure, BLE- not connected and console-not connected -- Disable Trust Zone File generation

    Case 9: RNBD is secure, BLE- connected, console-connected sercom are secure and RNBD non secure API's Gen--False -- Disable Trust Zone file generation
    Case 10: RNBD is secure, BLE- connected or console-connected sercom are secure and RNBD non secure API's Gen--False -- Disable Trust Zone file generation
    Case 11: RNBD is secure, BLE- not connected and console-not connected and RNBD non secure API's Gen--False -- Disable Trust Zone File generation'''

    #RNBD is non secure scenarios
    if RNBD_TrustZone_Variables["RNBD_NON_SECURE"] == True:
        #BLE sercom check - Case 4
        if ConnectedInst['InterfaceSercomInst'] != '':
            if RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == False:
                rnbdTrustZoneFiles[0].setEnabled(True)
                rnbdTrustZoneFiles[1].setEnabled(True)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})
        #Console Sercom check  - Case 5
        if ConnectedInst["ConsoleSercomInst"] != '':
            if RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == False:
                rnbdTrustZoneFiles[0].setEnabled(True)
                rnbdTrustZoneFiles[1].setEnabled(True)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})
        ##Case 6
        if ConnectedInst['InterfaceSercomInst'] != '' and  ConnectedInst["ConsoleSercomInst"] != '':
            if RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == True and RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == True:
                rnbdTrustZoneFiles[0].setEnabled(False)
                rnbdTrustZoneFiles[1].setEnabled(False)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : False})
        # Case 7
        elif ConnectedInst['InterfaceSercomInst'] != '' or  ConnectedInst["ConsoleSercomInst"] != '':
            if ConnectedInst['InterfaceSercomInst'] != '' and RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == True:
                rnbdTrustZoneFiles[0].setEnabled(False)
                rnbdTrustZoneFiles[1].setEnabled(False)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : False})
            if ConnectedInst['ConsoleSercomInst'] != '' and RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == True:
                rnbdTrustZoneFiles[0].setEnabled(False)
                rnbdTrustZoneFiles[1].setEnabled(False)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : False})
        ##case 8
        else:
            rnbdTrustZoneFiles[0].setEnabled(False)
            rnbdTrustZoneFiles[1].setEnabled(False)
            RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : False})

    ## RNBD is secure scenarios
    #Case 1
    elif RNBD_TrustZone_Variables["RNBD_NON_SECURE"] == False:
        if RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"] == True:
            rnbdTrustZoneFiles[0].setEnabled(True)
            rnbdTrustZoneFiles[1].setEnabled(True)
            RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})

        # BLE sercom check - Case 2
        if ConnectedInst['InterfaceSercomInst'] != '':
            if RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == True:
                rnbdTrustZoneFiles[0].setEnabled(True)
                rnbdTrustZoneFiles[1].setEnabled(True)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})
                Log.writeErrorMessage("User_Error:RNBD Sercom dependency 0 cannot be Non secure while RNBD is secure")

        #console sercom check - Case 3
        if ConnectedInst["ConsoleSercomInst"] != '':
            if RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == True:
                rnbdTrustZoneFiles[0].setEnabled(True)
                rnbdTrustZoneFiles[1].setEnabled(True)
                RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})
                Log.writeErrorMessage("User_Error:RNBD Sercom dependency 1 cannot be Non secure while RNBD is secure")
        
        # Case 9
        if ConnectedInst['InterfaceSercomInst'] != '' and ConnectedInst["ConsoleSercomInst"] != '':
            if RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == False and RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == False and RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"] == False:
                TrustZoneAppicationTypecheck()

        ##Case 10
        elif ConnectedInst['InterfaceSercomInst'] != '' or ConnectedInst["ConsoleSercomInst"] != '':
            if ConnectedInst['InterfaceSercomInst'] != '' and RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"] == False and RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"] == False:
                TrustZoneAppicationTypecheck()

            if ConnectedInst['ConsoleSercomInst'] != '' and RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"] == False and RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"] == False:
                TrustZoneAppicationTypecheck()

        ##Case 11
        else:
            if RNBD_TrustZone_Variables["RNBD_SECURE_API_GEN_CHECK"] == False:
                TrustZoneAppicationTypecheck()



## TrustZone File generation check based on Application type
def TrustZoneAppicationTypecheck():
    if ApplicationType == 'NONE':
        rnbdTrustZoneFiles[0].setEnabled(False)
        rnbdTrustZoneFiles[1].setEnabled(False)
        RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : False})
    else:
        rnbdTrustZoneFiles[0].setEnabled(True)
        rnbdTrustZoneFiles[1].setEnabled(True)
        RNBD_TrustZone_Variables.update({"TRUST_ZONE_FILE_GEN_CHECK" : True})

##################################################################################################################################
## Trust Zone update callback
def Trust_Zone_Option_Update(symbol,event):
    eventId = event['id'].split('_',1)
    eventBool = True if event["value"]=='True' else False
    res = list(re.findall(r'(\w+?)(\d+)', eventId[0]))
    if event["id"] == "RN_HOST_TRUST_ZONE_OPTIONS":
        if event["value"] == True:
            RNBD_TrustZone_Variables.update({"RNBD_NON_SECURE":False})
            updateRNBDMarkupVariable()
            
            if ConnectedInst['InterfaceSercomInst'] != '':
                RNBD_TrustZone_Variables.update({"BLE_SERCOM_NON_SECURE" : Database.getSymbolValue("core", ConnectedInst['InterfaceSercomInst'].upper() + "_IS_NON_SECURE")})          
                updateInterfaceSercomMarkupVariable()
                    
            if ConnectedInst['ConsoleSercomInst'] != '':
                RNBD_TrustZone_Variables.update({"CONSOLE_SERCOM_NON_SECURE": Database.getSymbolValue("core", ConnectedInst['ConsoleSercomInst'].upper() + "_IS_NON_SECURE")})          
                updateConsoleSercomMarkupVariable()
            non_secure_entry_File_check()
            rnPinTrustZoneSecureComment.setVisible(True)
            rnPinTrustZoneNonSecureComment.setVisible(False)
    
        elif event["value"] == False:
            RNBD_TrustZone_Variables.update({"RNBD_NON_SECURE":True})
            updateRNBDMarkupVariable()

            if ConnectedInst['InterfaceSercomInst'] != '':
                RNBD_TrustZone_Variables.update({"BLE_SERCOM_NON_SECURE": Database.getSymbolValue("core", ConnectedInst['InterfaceSercomInst'].upper() + "_IS_NON_SECURE")})
                updateInterfaceSercomMarkupVariable()       
                        
            if ConnectedInst['ConsoleSercomInst'] != '':
                RNBD_TrustZone_Variables.update({"CONSOLE_SERCOM_NON_SECURE": Database.getSymbolValue("core", ConnectedInst['ConsoleSercomInst'].upper() + "_IS_NON_SECURE")})
                updateConsoleSercomMarkupVariable()        
            non_secure_entry_File_check()
            rnPinTrustZoneSecureComment.setVisible(False)
            rnPinTrustZoneNonSecureComment.setVisible(True)

    else:
        if 'SERCOM' and '_IS_NON_SECURE' in event['id']:
            peripheralTrustZone['SercomInst_Non_secure'].update({event['id']:event['value']})
            sercom = (event['id'].split('_'))
            if ConnectedInst['InterfaceSercomInst'] != '':
                if ConnectedInst['InterfaceSercomInst'].upper() == sercom[0] :
                    RNBD_TrustZone_Variables.update({"BLE_SERCOM_NON_SECURE": event['value']})
                    updateInterfaceSercomMarkupVariable()
                    updateRNBDMarkupVariable()
            
            if ConnectedInst['ConsoleSercomInst'] != '':
                if ConnectedInst['ConsoleSercomInst'].upper() == sercom[0] :
                    RNBD_TrustZone_Variables.update({"CONSOLE_SERCOM_NON_SECURE": event['value']})
                    updateConsoleSercomMarkupVariable() 
                    updateRNBDMarkupVariable()
            non_secure_entry_File_check()        
                    
#########################################################################################################
#                               Module Dependencies Harmony Callback
#########################################################################################################
def onAttachmentConnected(source, target):
    #global InterfaceSercomInst
    #global DelayServiceInst
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    targetID = target["id"]  
    #print(source,target)
    #print("remoteId:",remoteID)
    if(source["id"] == "RNBD_USART_Dependency"):
        rnHostLibobjects.update({"SercomComponent":remoteComponent})
        symbolID = remoteComponent.getSymbolByID("USART_OPERATING_MODE")
        usart_Operating_mode = symbolID.getSelectedKey()       
        #if usart_Operating_mode != 'RING_BUFFER':
        #    symbolID.setSelectedKey("RING_BUFFER")
        #symbolID.setReadOnly(True)
        rnHostLibobjects.update({"Sercom_oper_symb_ID":symbolID})
        ConnectedInst.update({'InterfaceSercomInst':str(remoteID)})
        sercomIsNonSecure = Database.getSymbolValue("core", ConnectedInst['InterfaceSercomInst'].upper() + "_IS_NON_SECURE")
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INST",str(remoteID).upper())
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",sercomIsNonSecure)
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_INST",str(remoteID).upper())
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_INST",str(remoteID).upper())
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",sercomIsNonSecure)
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",sercomIsNonSecure)
        updateRNBDMarkupVariable()
        if RNBD_TrustZone_Variables["RNBD_NON_SECURE"] == True and sercomIsNonSecure == False or RNBD_TrustZone_Variables["RNBD_NON_SECURE"] == False and sercomIsNonSecure == True:
            rnbdTrustZoneFiles[0].setEnabled(True)
            rnbdTrustZoneFiles[1].setEnabled(True)
            TrustZoneFileGenCheck = True
        SercomConnected = True
        #print("sercomIsNonSecure",sercomIsNonSecure)
    
def onAttachmentDisconnected(source, target):
    #print("onAttachmentDisconnected")
    if source["id"] == "RNBD_USART_Dependency":
        if SercomConnected == True:
            rnHostLibobjects["Sercom_oper_symb_ID"].setReadOnly(False)
            SercomConnected = false

#def onDependencyDisconnected(info):
#    #print("onDependencyDisconnected",info)
#    if(info["dependencyID"] == "RNBD_USART_Dependency"):
#        if SercomConnected == True:
#            rnHostLibobjects["Sercom_oper_symb_ID"].setReadOnly(False)
#            SercomConnected = False

#####################################################################################
#                            Component Generic Harmony API's 
#####################################################################################

def instantiateComponent(rnHostLib):
    Log.writeInfoMessage("Initiating RN HOST LIBRARY")
    #print(rnHostLib)
    configName = Variables.get("__CONFIGURATION_NAME")
    #print configName
    processor = Variables.get("__PROCESSOR")
    #print processor
    
    rnHostLib.setDependencyEnabled("RNBD_USART_Dependency",True)
    components = Database.getActiveComponentIDs()

    #rnHostLib.setDependencyEnabled("Delay_Service_Dependency",True)
    #components = Database.getActiveComponentIDs()
        
    rnHostLibobjects.update({"rnComponent":rnHostLib})
        
    # RN Host Lib configuration options
    rnHostlibmenu  = rnHostLib.createMenuSymbol("RN_HOST_LIB_MENU",None)
    rnHostlibmenu.setLabel("HOST LIBRARY CONFIGURATION")
    rnHostlibmenu.setDescription("Select the required configuration")
    
    if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":
        SercomInstance = Sercom_Instances_Get()
        TimerInstance,RTCInstance = Timer_Instances_Get()
        #print("Trace1",SercomInstance)
        Dependencies = []
        Dependencies.append("RN_HOST_TRUST_ZONE_OPTIONS")
        peripheralTrustZone.update({'SercomInst_Non_secure':{}})
        sercom_nonSecure = {}
        for i in range(SercomInstance):
            Dependencies.append("core." + ('sercom'+str(i)).upper() + "_IS_NON_SECURE")
            sercom_secure_key = ('Sercom'+str(i)).upper()+'_IS_NON_SECURE'
            sercom_secure_value = Database.getSymbolValue("core", ('sercom'+str(i)).upper() + "_IS_NON_SECURE")
            sercom_nonSecure.update({sercom_secure_key:sercom_secure_value})
        peripheralTrustZone.update({'SercomInst_Non_secure':sercom_nonSecure})
        #print("peripheralTrustZone",peripheralTrustZone)
        
        peripheralTrustZone.update({'TCInst_Non_secure':{}})
        tc_nonSecure = {}
        for i in range(TimerInstance):
            Dependencies.append("core." + ('tc'+str(i)).upper() + "_IS_NON_SECURE")
            tc_secure_key = ('tc'+str(i)).upper()+'_IS_NON_SECURE'
            tc_secure_value = Database.getSymbolValue("core", ('tc'+str(i)).upper() + "_IS_NON_SECURE")
            tc_nonSecure.update({tc_secure_key:tc_secure_value})
        peripheralTrustZone.update({'TCInst_Non_secure':tc_nonSecure})
        
        peripheralTrustZone.update({'RTCInst_Non_secure':{}})
        rtc_nonSecure = {}
        if RTCInstance !=0:
            Dependencies.append("core." + ('rtc').upper() + "_IS_NON_SECURE")
            rtc_secure_key = ('rtc').upper()+'_IS_NON_SECURE'
            rtc_secure_value = Database.getSymbolValue("core", ('rtc').upper() + "_IS_NON_SECURE")
            rtc_nonSecure.update({rtc_secure_key:rtc_secure_value})
        peripheralTrustZone.update({'RTCInst_Non_secure':rtc_nonSecure})
            
        #rnHostlibprojectmenu = rnHostLib.createMenuSymbol("RN_HOST_TRUST_ZONE_MENU",None)
        #rnHostlibprojectmenu.setLabel("TRUST ZONE CONFIGURATION")
        #rnHostlibprojectmenu.setDescription("Select the Trust Zone Configuration")
        
        rnHostlibtrustzoneMenu = rnHostLib.createBooleanSymbol("RN_HOST_TRUST_ZONE_OPTIONS",rnHostlibmenu)
        rnHostlibtrustzoneMenu.setLabel("Enable RNBD Secure")
        rnHostlibtrustzoneMenu.setDescription("Select the Trust zone option for project Generation")
        rnHostlibtrustzoneMenu.setDefaultValue(False)
        rnHostlibtrustzoneMenu.setDependencies(Trust_Zone_Option_Update,Dependencies)
        rnHostLibobjects.update({"TrustZoneFile":rnHostlibtrustzoneMenu}) 
        
        global rnPinTrustZoneSecureComment
        rnPinTrustZoneSecureComment = rnHostLib.createCommentSymbol(None,rnHostlibtrustzoneMenu)
        rnPinTrustZoneSecureComment.setVisible(False)
        rnPinTrustZoneSecureComment.setLabel(BTPinSecureMsg)

        global rnPinTrustZoneNonSecureComment
        rnPinTrustZoneNonSecureComment = rnHostLib.createCommentSymbol(None,rnHostlibmenu)
        rnPinTrustZoneNonSecureComment.setVisible(True)
        rnPinTrustZoneNonSecureComment.setLabel(BTPinNonSecureMsg)

        rnHostlibapigenerationMenu = rnHostLib.createBooleanSymbol("RN_SECURE_API_GENERATION",rnHostlibtrustzoneMenu)
        rnHostlibapigenerationMenu.setLabel("Generate RNBD Non Secure Entry")
        rnHostlibapigenerationMenu.setDescription("Select the Trust zone option for project Generation")
        rnHostlibapigenerationMenu.setDefaultValue(False)
        rnHostlibapigenerationMenu.setEnabled(False)
        rnHostlibapigenerationMenu.setVisible(False)
        rnHostlibapigenerationMenu.setDependencies(SecureAPIGenerationOptionUpdate,["RN_HOST_TRUST_ZONE_OPTIONS"])
        #rnHostLibobjects.update({"TrustZoneFile":rnHostlibtrustzoneMenu}) 
        
        #global nonSecureFileObj
        #global localnonSecureFileobj
        #coreComponent = Database.getComponentByID('core')
        #nonSecureFileObj = coreComponent.getSymbolByID("NONSECURE_ENTRY_C")
        #print("nonSecureFileObj",nonSecureFileObj)
        
        nonSecureEntrySourceFile = rnHostLib.createFileSymbol('NON_SECURE_ENTRY_SOURCE',None)
        nonSecureEntrySourceFile.setSourcePath('driver/templates/rnbd_non_secure_entry.c.ftl')
        nonSecureEntrySourceFile.setOverwrite(True)
        nonSecureEntrySourceFile.setOutputName("non_secure_entry.c")
        nonSecureEntrySourceFile.setDestPath("../../trustZone/rnbd/")
        nonSecureEntrySourceFile.setProjectPath("trustZone/rnbd/")
        nonSecureEntrySourceFile.setType("SOURCE")
        nonSecureEntrySourceFile.setSecurity("SECURE")
        nonSecureEntrySourceFile.setMarkup(True)
        nonSecureEntrySourceFile.setEnabled(False)
        nonSecureEntrySourceFile.setDependencies(TrustZoneFileGenerationUpdate,["RN_SECURE_API_GENERATION"])
        
        nonSecureEntryHeaderFile = rnHostLib.createFileSymbol('NON_SECURE_ENTRY_HEADER',None)
        nonSecureEntryHeaderFile.setSourcePath('driver/templates/rnbd_non_secure_entry.h.ftl')
        nonSecureEntryHeaderFile.setOverwrite(True)
        nonSecureEntryHeaderFile.setOutputName("non_secure_entry.h")
        nonSecureEntryHeaderFile.setDestPath("../../trustZone/rnbd/")
        nonSecureEntryHeaderFile.setProjectPath("trustZone/rnbd/")
        nonSecureEntryHeaderFile.setType("HEADER")
        nonSecureEntryHeaderFile.setSecurity("NON_SECURE")
        nonSecureEntryHeaderFile.setMarkup(True)
        nonSecureEntryHeaderFile.setEnabled(False)
        
        global rnbdTrustZoneFiles 
        rnbdTrustZoneFiles = []
        rnbdTrustZoneFiles.append(nonSecureEntrySourceFile)
        rnbdTrustZoneFiles.append(nonSecureEntryHeaderFile)
        updateInterfaceSercomMarkupVariable()
        updateConsoleSercomMarkupVariable()

        #rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_NON_SECURE_ENTRY",secureApiGenerationCheck)
        #rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_NON_SECURE_ENTRY",secureApiGenerationCheck)

    rnHostlibSelectBLEModuleMenu = rnHostLib.createComboSymbol("RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE",rnHostlibmenu,Module_Type_options)
    rnHostlibSelectBLEModuleMenu.setLabel("Select Module Type")
    rnHostlibSelectBLEModuleMenu.setDescription("Select the BLE module type")
    rnHostlibSelectBLEModuleMenu.setValue("RNBD")
        
    #rnHostlibAppMenu.setDependencies(app_Choice_callback,["RN_HOST_EXAMPLE_APPLICATION_CHOICE"])
    #print('%%%%%%%',rnHostlibAppMenu.getValue())
    
    #rnHostlibPinSettingsMsg  = rnHostLib.createCommentSymbol("RN_HOST_PIN_SETTINGS_MSG_POP_UP", rnHostlibmenu)
    #rnHostlibPinSettingsMsg.setLabel("***NOTE:Select the BLE_TX, BLE_RX, RX_IND and BT_RST pins inside pin configuration using same naming***")

    ## GPIO PORT DEPENDENCIES 
    get_port_pin_dependencies()

    rnHostPinConfigmenu  = rnHostLib.createMenuSymbol("RN_HOST_LIB_PIN_MENU",rnHostlibmenu)
    rnHostPinConfigmenu.setLabel("Module Pin Selections")
    rnHostPinConfigmenu.setDescription("Select the required Pin configuration")

    #global rnHostGPIOUpdateSymbol
    #rnHostGPIOUpdateSymbol = rnHostLib.createCommentSymbol("BLE_GPIO_CONFIG_UPDATE",rnHostPinConfigmenu)
   # rnHostGPIOUpdateSymbol.setVisible(False)
    #rnHostGPIOUpdateSymbol.setDependencies(GPIO_Update_Callback,gpio_dependency)

    global rnHostRstPin
    rnHostRstPin = rnHostLib.createStringSymbol("BLE_RST_PIN_UPDATE",rnHostPinConfigmenu)
    rnHostRstPin.setLabel("BT Reset Pin")
    rnHostRstPin.setReadOnly(True)
    #rnHostRstPin.setDefaultValue(False)
    rnHostRstPin.setDependencies(GPIO_Update_Callback,gpio_dependency)
    global rnHostRstSet
    rnHostRstSet = rnHostLib.createBooleanSymbol("BLE_RST_PIN_SELECTED",rnHostPinConfigmenu)
    rnHostRstSet.setLabel("BT Reset Pin Selected")
    rnHostRstSet.setVisible(False)
    rnHostRstSet.setDefaultValue(False)
    rnHostRstSet.setDependencies(RNBDPinSelectionUpdatesCallback,['BLE_RST_PIN_UPDATE'])

    global rnHostRstPinMsg
    rnHostRstPinMsg = rnHostLib.createCommentSymbol(None,rnHostPinConfigmenu)
    rnHostRstPinMsg.setVisible(True)
    rnHostRstPinMsg.setLabel(rst_pin_config_msg)

    global rnHostStatusPinCheck
    rnHostStatusPinCheck = rnHostLib.createBooleanSymbol('BT_STATUS_PIN_CHECK',rnHostPinConfigmenu)
    rnHostStatusPinCheck.setLabel('Enable Connection Status Pin')
    rnHostStatusPinCheck.setDefaultValue(False)

    global rnHostStatusPin1
    rnHostStatusPin1 = rnHostLib.createStringSymbol("BLE_STATUS1_PIN_UPDATE",rnHostStatusPinCheck)
    rnHostStatusPin1.setLabel("BT Status 1 Pin")
    rnHostStatusPin1.setReadOnly(True)
    rnHostStatusPin1.setVisible(False)
    #rnHostStatusPin1.setDefaultValue(False)
    rnHostStatusPin1.setDependencies(BT_Pin_Functionality_Update,["BT_STATUS_PIN_CHECK"])

    global rnHostStatusPin1Msg
    rnHostStatusPin1Msg = rnHostLib.createCommentSymbol(None,rnHostStatusPinCheck)
    rnHostStatusPin1Msg.setVisible(False)
    rnHostStatusPin1Msg.setLabel(status_pin1_config_msg)

    global rnHostStatusPin2
    rnHostStatusPin2 = rnHostLib.createStringSymbol("BLE_STATUS2_PIN_UPDATE",rnHostStatusPinCheck)
    rnHostStatusPin2.setLabel("BT Status 2 Pin")
    #rnHostStatusPin2.setDefaultValue(False)
    rnHostStatusPin2.setReadOnly(True)
    rnHostStatusPin2.setVisible(False)
    #rnHostStatusPin2.setDependencies(BT_Status_Pin_Functionality_Update,[])

    global rnHostStatusPin2Msg
    rnHostStatusPin2Msg = rnHostLib.createCommentSymbol(None,rnHostStatusPinCheck)
    rnHostStatusPin2Msg.setVisible(False)
    rnHostStatusPin2Msg.setLabel(status_pin2_config_msg)

    global rnHostRxIndPinCheck
    rnHostRxIndPinCheck = rnHostLib.createBooleanSymbol('BT_RX_IND_PIN_CHECK',rnHostPinConfigmenu)
    rnHostRxIndPinCheck.setLabel('Enable RX IND Pin')
    rnHostRxIndPinCheck.setDefaultValue(False)

    global rnHostRxIndPinSelected
    rnHostRxIndPinSelected = rnHostLib.createStringSymbol("BLE_RX_IND_PIN_UPDATE",rnHostRxIndPinCheck)
    rnHostRxIndPinSelected.setLabel("BT RX IND Pin")
    rnHostRxIndPinSelected.setReadOnly(True)
    rnHostRxIndPinSelected.setVisible(False)
    #rnHostStatusPin1.setDefaultValue(False)
    rnHostRxIndPinSelected.setDependencies(BT_Pin_Functionality_Update,["BT_RX_IND_PIN_CHECK"])

    global rnHostRxIndPinMsg
    rnHostRxIndPinMsg = rnHostLib.createCommentSymbol(None,rnHostRxIndPinCheck)
    rnHostRxIndPinMsg.setVisible(False)
    rnHostRxIndPinMsg.setLabel(rx_ind_Pin_config_msg)

    global rnHostSystemModePinCheck
    rnHostSystemModePinCheck = rnHostLib.createBooleanSymbol('BT_SYS_MODE_PIN_CHECK',rnHostPinConfigmenu)
    rnHostSystemModePinCheck.setLabel('Enable BT Mode Pin')
    rnHostSystemModePinCheck.setDefaultValue(False)

    global rnHostSystemModePinSelected
    rnHostSystemModePinSelected = rnHostLib.createStringSymbol("BLE_SYS_MODE_PIN_UPDATE",rnHostSystemModePinCheck)
    rnHostSystemModePinSelected.setLabel("BT Mode Pin")
    rnHostSystemModePinSelected.setReadOnly(True)
    rnHostSystemModePinSelected.setVisible(False)
    rnHostSystemModePinSelected.setDependencies(BT_Pin_Functionality_Update,["BT_SYS_MODE_PIN_CHECK"])

    global rnHostSysModePinMsg
    rnHostSysModePinMsg = rnHostLib.createCommentSymbol(None,rnHostSystemModePinCheck)
    rnHostSysModePinMsg.setVisible(False)
    rnHostSysModePinMsg.setLabel(sys_mode_Pin_config_msg)


    #Application choice
    rnHostlibAppMenu  = rnHostLib.createComboSymbol("RN_HOST_EXAMPLE_APPLICATION_CHOICE",rnHostlibmenu,Application_Menu_options)
    rnHostlibAppMenu.setLabel("Select example application")
    rnHostlibAppMenu.setDescription("Select one example application to experience RN Host library")
    rnHostlibAppMenu.setDefaultValue("NONE")

    ########################################################################
    
    rn487xBLEInterfaceSourceFile = rnHostLib.createFileSymbol("RN487X_INTERFACE_C",None)
    rn487xBLEInterfaceSourceFile.setSourcePath("driver/templates/rn487x_interface.c.ftl")
    rn487xBLEInterfaceSourceFile.setOutputName("rn487x_interface.c")
    rn487xBLEInterfaceSourceFile.setOverwrite(True)
    rn487xBLEInterfaceSourceFile.setDestPath("../../rn487x/")
    rn487xBLEInterfaceSourceFile.setProjectPath("rn487x/")
    rn487xBLEInterfaceSourceFile.setType("SOURCE")
    rn487xBLEInterfaceSourceFile.setMarkup(True)
    rn487xBLEInterfaceSourceFile.setEnabled(False)
    rn487xBLEInterfaceSourceFile.setDependencies(rn487xBLEInterfaceSourceCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
  #  
    rn487xBLEInterfaceHeaderFile = rnHostLib.createFileSymbol("RN487X_INTERFACE_H",None)
    rn487xBLEInterfaceHeaderFile.setSourcePath("driver/templates/rn487x_interface.h.ftl")
    rn487xBLEInterfaceHeaderFile.setOutputName("rn487x_interface.h")
    rn487xBLEInterfaceHeaderFile.setOverwrite(True)
    rn487xBLEInterfaceHeaderFile.setDestPath("../../rn487x/")
    rn487xBLEInterfaceHeaderFile.setProjectPath("rn487x/")
    rn487xBLEInterfaceHeaderFile.setType("HEADER")
    rn487xBLEInterfaceHeaderFile.setMarkup(True)
    rn487xBLEInterfaceHeaderFile.setEnabled(False)
    rn487xBLEInterfaceHeaderFile.setDependencies(rn487xBLEInterfaceHeaderCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    #
    rn487xBLEFeatureSourceFile = rnHostLib.createFileSymbol("RN487X_C",None)
    rn487xBLEFeatureSourceFile.setSourcePath("driver/templates/rn487x.c.ftl")
    rn487xBLEFeatureSourceFile.setOutputName("rn487x.c")
    rn487xBLEFeatureSourceFile.setOverwrite(True)
    rn487xBLEFeatureSourceFile.setDestPath("../../rn487x/")
    rn487xBLEFeatureSourceFile.setProjectPath("rn487x/")
    rn487xBLEFeatureSourceFile.setType("SOURCE")
    rn487xBLEFeatureSourceFile.setMarkup(True)
    rn487xBLEFeatureSourceFile.setEnabled(False)
    rn487xBLEFeatureSourceFile.setDependencies(rn487xBLEFeatureSourceCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    #
    rn487xBLEFeatureHeaderFile = rnHostLib.createFileSymbol("RN487X_H",None)
    rn487xBLEFeatureHeaderFile.setSourcePath("driver/templates/rn487x.h.ftl")
    rn487xBLEFeatureHeaderFile.setOutputName("rn487x.h")
    rn487xBLEFeatureHeaderFile.setOverwrite(True)
    rn487xBLEFeatureHeaderFile.setDestPath("../../rn487x/")
    rn487xBLEFeatureHeaderFile.setProjectPath("rn487x/")
    rn487xBLEFeatureHeaderFile.setType("HEADER")
    rn487xBLEFeatureHeaderFile.setMarkup(True)
    rn487xBLEFeatureHeaderFile.setEnabled(False)
    rn487xBLEFeatureHeaderFile.setDependencies(rn487xBLEFeatureHeaderCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    ##
    #Add RNBD_BLE Interface files
    rnbdBLEInterfaceSourceFile = rnHostLib.createFileSymbol("RNBD_INTERFACE_C",None)
    rnbdBLEInterfaceSourceFile.setSourcePath("driver/templates/rnbd_interface.c.ftl")
    rnbdBLEInterfaceSourceFile.setOutputName("rnbd_interface.c")
    rnbdBLEInterfaceSourceFile.setOverwrite(True)
    rnbdBLEInterfaceSourceFile.setDestPath("../../rnbd/")
    rnbdBLEInterfaceSourceFile.setProjectPath("rnbd/")
    rnbdBLEInterfaceSourceFile.setType("SOURCE")
    rnbdBLEInterfaceSourceFile.setMarkup(True)
    rnbdBLEInterfaceSourceFile.setEnabled(True)
    rnbdBLEInterfaceSourceFile.setDependencies(rnbdBLEInterfaceSourceCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
  # # 
    rnbdBLEInterfaceHeaderFile = rnHostLib.createFileSymbol("RNBD_INTERFACE_H",None)
    rnbdBLEInterfaceHeaderFile.setSourcePath("driver/templates/rnbd_interface.h.ftl")
    rnbdBLEInterfaceHeaderFile.setOutputName("rnbd_interface.h")
    rnbdBLEInterfaceHeaderFile.setOverwrite(True)
    rnbdBLEInterfaceHeaderFile.setDestPath("../../rnbd/")
    rnbdBLEInterfaceHeaderFile.setProjectPath("rnbd/")
    rnbdBLEInterfaceHeaderFile.setType("HEADER")
    rnbdBLEInterfaceHeaderFile.setMarkup(True)
    rnbdBLEInterfaceHeaderFile.setEnabled(True)
    rnbdBLEInterfaceHeaderFile.setDependencies(rnbdBLEInterfaceHeaderCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    ##
    rnbdBLEFeatureSourceFile = rnHostLib.createFileSymbol("RNBD_C",None)
    rnbdBLEFeatureSourceFile.setSourcePath("driver/templates/rnbd.c.ftl")
    rnbdBLEFeatureSourceFile.setOutputName("rnbd.c")
    rnbdBLEFeatureSourceFile.setOverwrite(True)
    rnbdBLEFeatureSourceFile.setDestPath("../../rnbd/")
    rnbdBLEFeatureSourceFile.setProjectPath("rnbd/")
    rnbdBLEFeatureSourceFile.setType("SOURCE")
    rnbdBLEFeatureSourceFile.setMarkup(True)
    rnbdBLEFeatureSourceFile.setEnabled(True)
    rnbdBLEFeatureSourceFile.setDependencies(rnbdBLEFeatureSourceCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    ###
    rnbdBLEFeatureHeaderFile = rnHostLib.createFileSymbol("RNBD_H",None)
    rnbdBLEFeatureHeaderFile.setSourcePath("driver/templates/rnbd.h.ftl")
    rnbdBLEFeatureHeaderFile.setOutputName("rnbd.h")
    rnbdBLEFeatureHeaderFile.setOverwrite(True)
    rnbdBLEFeatureHeaderFile.setDestPath("../../rnbd/")
    rnbdBLEFeatureHeaderFile.setProjectPath("rnbd/")
    rnbdBLEFeatureHeaderFile.setType("HEADER")
    rnbdBLEFeatureHeaderFile.setMarkup(True)
    rnbdBLEFeatureHeaderFile.setEnabled(True)
    rnbdBLEFeatureHeaderFile.setDependencies(rnbdBLEFeatureHeaderCallback,["RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    ########################################################################
    
   ## #Example Files inclusion
    rnExampleTrpUartAppSourceFile = rnHostLib.createFileSymbol(None,None)
    rnExampleTrpUartAppSourceFile.setSourcePath("driver/templates/transparent_uart.c.ftl")
    rnExampleTrpUartAppSourceFile.setOutputName("rnbd_example.c")
    rnExampleTrpUartAppSourceFile.setOverwrite(True)
    rnExampleTrpUartAppSourceFile.setDestPath("../../examples/")
    rnExampleTrpUartAppSourceFile.setProjectPath("examples/")
    rnExampleTrpUartAppSourceFile.setType("SOURCE")
    rnExampleTrpUartAppSourceFile.setMarkup(True)
    rnExampleTrpUartAppSourceFile.setEnabled(False)
    rnExampleTrpUartAppSourceFile.setDependencies(rnHostTrpUartExpAppSourceCallback,["RN_HOST_EXAMPLE_APPLICATION_CHOICE","RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])    
   # 
    rnExampleTrpUartAppHeaderFile = rnHostLib.createFileSymbol(None,None)
    rnExampleTrpUartAppHeaderFile.setSourcePath("driver/templates/transparent_uart.h.ftl")
    rnExampleTrpUartAppHeaderFile.setOutputName("rnbd_example.h")
    rnExampleTrpUartAppHeaderFile.setOverwrite(True)
    rnExampleTrpUartAppHeaderFile.setDestPath("../../examples/")
    rnExampleTrpUartAppHeaderFile.setProjectPath("examples/")
    rnExampleTrpUartAppHeaderFile.setType("HEADER")
    rnExampleTrpUartAppHeaderFile.setMarkup(True)
    rnExampleTrpUartAppHeaderFile.setEnabled(False)
    rnExampleTrpUartAppHeaderFile.setDependencies(rnHostTrpUartExpAppHeaderCallback,["RN_HOST_EXAMPLE_APPLICATION_CHOICE","RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])
    
    rnExampleBscDataExcAppSourceFile = rnHostLib.createFileSymbol(None,None)
    rnExampleBscDataExcAppSourceFile.setSourcePath("driver/templates/BasicDataExchange.c.ftl")
    rnExampleBscDataExcAppSourceFile.setOutputName("rnbd_example.c")
    rnExampleBscDataExcAppSourceFile.setOverwrite(True)
    rnExampleBscDataExcAppSourceFile.setDestPath("../../examples/")
    rnExampleBscDataExcAppSourceFile.setProjectPath("examples/")
    rnExampleBscDataExcAppSourceFile.setType("SOURCE")
    rnExampleBscDataExcAppSourceFile.setMarkup(True)
    rnExampleBscDataExcAppSourceFile.setEnabled(False)
    rnExampleBscDataExcAppSourceFile.setDependencies(rnHostBasicDataExcExpAppSourceCallback,["RN_HOST_EXAMPLE_APPLICATION_CHOICE","RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"])  
    
    rnExampleBscDataExcAppHeaderFile = rnHostLib.createFileSymbol(None,None)
    rnExampleBscDataExcAppHeaderFile.setSourcePath("driver/templates/BasicDataExchange.h.ftl")
    rnExampleBscDataExcAppHeaderFile.setOutputName("rnbd_example.h")
    rnExampleBscDataExcAppHeaderFile.setOverwrite(True)
    rnExampleBscDataExcAppHeaderFile.setDestPath("../../examples/")
    rnExampleBscDataExcAppHeaderFile.setProjectPath("examples/")
    rnExampleBscDataExcAppHeaderFile.setType("HEADER")
    rnExampleBscDataExcAppHeaderFile.setMarkup(True)
    rnExampleBscDataExcAppHeaderFile.setEnabled(False)
    rnExampleBscDataExcAppHeaderFile.setDependencies(rnHostBasicDataExcExpAppHeaderCallback,["RN_HOST_EXAMPLE_APPLICATION_CHOICE","RN_HOST_SELECT_BLE_MODULE_TYPE_CHOICE"]) 
    
    
    rnHostLibFilesArray.append(rn487xBLEInterfaceSourceFile)
    rnHostLibFilesArray.append(rn487xBLEInterfaceHeaderFile)
    rnHostLibFilesArray.append(rn487xBLEFeatureSourceFile)
    rnHostLibFilesArray.append(rn487xBLEFeatureHeaderFile)
    rnHostLibFilesArray.append(rnbdBLEInterfaceSourceFile)
    rnHostLibFilesArray.append(rnbdBLEInterfaceHeaderFile)
    rnHostLibFilesArray.append(rnbdBLEFeatureSourceFile)
    rnHostLibFilesArray.append(rnbdBLEFeatureHeaderFile)
    rnHostLibFilesArray.append(rnExampleTrpUartAppSourceFile)
    rnHostLibFilesArray.append(rnExampleTrpUartAppHeaderFile)
    rnHostLibFilesArray.append(rnExampleBscDataExcAppSourceFile)
    rnHostLibFilesArray.append(rnExampleBscDataExcAppHeaderFile)

    
    if Variables.get("__TRUSTZONE_ENABLED") != None and Variables.get("__TRUSTZONE_ENABLED") == "true":   
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("TRUST_ZONE_ENABLED",True)
            rnHostLibFilesArray[i].addMarkupVariable("BT_STATUS_PIN_CHECK_ENABLE",False)
            rnHostLibFilesArray[i].addMarkupVariable("RNBD_NON_SECURE",True)
            rnHostLibFilesArray[i].addMarkupVariable("RNBD_NON_SECURE_ENTRY",False)
            rnHostLibFilesArray[i].addMarkupVariable("BT_RX_IND_PIN_CHECK_ENABLE",False) 
            rnHostLibFilesArray[i].addMarkupVariable("BT_SYS_MODE_PIN_CHECK_ENABLE",False)
            rnHostLibFilesArray[i].addMarkupVariable("BT_RST_Pin_Selected",False)
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
            rnHostLibFilesArray[i].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_INTERFACE_NON_SECURE",RNBD_TrustZone_Variables["BLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[0].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[1].addMarkupVariable("SERCOM_CONSOLE_NON_SECURE",RNBD_TrustZone_Variables["CONSOLE_SERCOM_NON_SECURE"])
        rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_NON_SECURE",True)
        rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_NON_SECURE",True)
        rnbdTrustZoneFiles[0].addMarkupVariable("RNBD_NON_SECURE_ENTRY",False)
        rnbdTrustZoneFiles[1].addMarkupVariable("RNBD_NON_SECURE_ENTRY",False)
        
    else:
        for i in range(len(rnHostLibFilesArray)):
            rnHostLibFilesArray[i].addMarkupVariable("TRUST_ZONE_ENABLED",False)
            rnHostLibFilesArray[i].addMarkupVariable("BT_STATUS_PIN_CHECK_ENABLE",False)
            rnHostLibFilesArray[i].addMarkupVariable("BT_SYS_MODE_PIN_CHECK_ENABLE",False)
            rnHostLibFilesArray[i].addMarkupVariable("BT_RX_IND_PIN_CHECK_ENABLE",False) 
            rnHostLibFilesArray[i].addMarkupVariable("BT_RST_Pin_Selected",False)
    
    check_update_pins()
    
def finalizeComponent(rnHostLib):
    #print("finalizeComponent")
    pass
    
    
def destroyComponent(snifferblock) :
    pass
     
    