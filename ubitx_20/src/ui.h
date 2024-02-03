// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: ubitx_20_ux

#ifndef _UBITX_20_UX_UI_H
#define _UBITX_20_UX_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
void ui_event_HomePanel(lv_event_t * e);
extern lv_obj_t * ui_HomePanel;
extern lv_obj_t * ui_topMenuPanel;
void ui_event_txStopButton(lv_event_t * e);
extern lv_obj_t * ui_txStopButton;
extern lv_obj_t * ui_txStopLabel;
void ui_event_switchVFO(lv_event_t * e);
extern lv_obj_t * ui_switchVFO;
extern lv_obj_t * ui_currentVFO;
void ui_event_bandDownButton(lv_event_t * e);
extern lv_obj_t * ui_bandDownButton;
void ui_event_bandDownLabel(lv_event_t * e);
extern lv_obj_t * ui_bandDownLabel;
void ui_event_bandUpButton(lv_event_t * e);
extern lv_obj_t * ui_bandUpButton;
void ui_event_bandUpLabel(lv_event_t * e);
extern lv_obj_t * ui_bandUpLabel;
void ui_event_modeSelectButton(lv_event_t * e);
extern lv_obj_t * ui_modeSelectButton;
extern lv_obj_t * ui_modeSelectLabel;
void ui_event_lockDisplayButton(lv_event_t * e);
extern lv_obj_t * ui_lockDisplayButton;
extern lv_obj_t * ui_locKDisplayLabel;
void ui_event_spkToggleButton(lv_event_t * e);
extern lv_obj_t * ui_spkToggleButton;
extern lv_obj_t * ui_spkToggleLabel;
extern lv_obj_t * ui_VFOPanel;
extern lv_obj_t * ui_VFOUpperPanel;
extern lv_obj_t * ui_RXTXPanel;
void ui_event_RXButton(lv_event_t * e);
extern lv_obj_t * ui_RXButton;
extern lv_obj_t * ui_RXButtonLabel;
void ui_event_TXButton(lv_event_t * e);
extern lv_obj_t * ui_TXButton;
extern lv_obj_t * ui_TXButtonLabel;
void ui_event_activeVFOPanel(lv_event_t * e);
extern lv_obj_t * ui_activeVFOPanel;
extern lv_obj_t * ui_activeFreq;
extern lv_obj_t * ui_modeSelectPanel;
void ui_event_LSBModeButton(lv_event_t * e);
extern lv_obj_t * ui_LSBModeButton;
extern lv_obj_t * ui_LSBModeLabel;
void ui_event_USBModeButton(lv_event_t * e);
extern lv_obj_t * ui_USBModeButton;
extern lv_obj_t * ui_USBModeLabel;
void ui_event_CWLModeButton(lv_event_t * e);
extern lv_obj_t * ui_CWLModeButton;
extern lv_obj_t * ui_CWLModeLabel;
void ui_event_CWUModeButton(lv_event_t * e);
extern lv_obj_t * ui_CWUModeButton;
extern lv_obj_t * ui_CWUModeLabel;
void ui_event_VFOLowerPanel(lv_event_t * e);
extern lv_obj_t * ui_VFOLowerPanel;
extern lv_obj_t * ui_VFOInactiveFreqPanel;
extern lv_obj_t * ui_inactiveFreq;
extern lv_obj_t * ui_inactiveMode;
extern lv_obj_t * ui_firmwarePanel;
extern lv_obj_t * ui_firmwareOS;
extern lv_obj_t * ui_firmwareVersion;
void ui_event_SMeterPanel(lv_event_t * e);
extern lv_obj_t * ui_SMeterPanel;
extern lv_obj_t * ui_Panel7;
void ui_event_splitButton(lv_event_t * e);
extern lv_obj_t * ui_splitButton;
extern lv_obj_t * ui_splitButtonLabel;
void ui_event_ritButton(lv_event_t * e);
extern lv_obj_t * ui_ritButton;
extern lv_obj_t * ui_ritButtonLabel;
void ui_event_ifsButton(lv_event_t * e);
extern lv_obj_t * ui_ifsButton;
extern lv_obj_t * ui_ifsButtonLabel;
void ui_event_attButton(lv_event_t * e);
extern lv_obj_t * ui_attButton;
extern lv_obj_t * ui_attButtonLabel;
extern lv_obj_t * ui_Panel1;
void ui_event_tuneRateSelection(lv_event_t * e);
extern lv_obj_t * ui_tuneRateSelection;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_Panel9;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Label20;
extern lv_obj_t * ui_Panel10;
extern lv_obj_t * ui_Bar2;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
void ui_event_bottomPanel(lv_event_t * e);
extern lv_obj_t * ui_bottomPanel;
void ui_event_cwSettingsPanel(lv_event_t * e);
extern lv_obj_t * ui_cwSettingsPanel;
void ui_event_cwInfoCol1Panel(lv_event_t * e);
extern lv_obj_t * ui_cwInfoCol1Panel;
void ui_event_cwInfoLabel(lv_event_t * e);
extern lv_obj_t * ui_cwInfoLabel;
void ui_event_cwKeySpeed(lv_event_t * e);
extern lv_obj_t * ui_cwKeySpeed;
void ui_event_cwSidetone(lv_event_t * e);
extern lv_obj_t * ui_cwSidetone;
void ui_event_cwInforCol2Panel(lv_event_t * e);
extern lv_obj_t * ui_cwInforCol2Panel;
void ui_event_cwKeyType(lv_event_t * e);
extern lv_obj_t * ui_cwKeyType;
void ui_event_cwKeySpeedUnits(lv_event_t * e);
extern lv_obj_t * ui_cwKeySpeedUnits;
void ui_event_cwSidetoneUnits(lv_event_t * e);
extern lv_obj_t * ui_cwSidetoneUnits;
extern lv_obj_t * ui_ATT_IFS_Panel;
extern lv_obj_t * ui_ATTPanel;
void ui_event_ATTgraph(lv_event_t * e);
extern lv_obj_t * ui_ATTgraph;
void ui_event_ATTGraphLabels(lv_event_t * e);
extern lv_obj_t * ui_ATTGraphLabels;
void ui_event_ATTGraphLabel(lv_event_t * e);
extern lv_obj_t * ui_ATTGraphLabel;
void ui_event_ATTValueLabel(lv_event_t * e);
extern lv_obj_t * ui_ATTValueLabel;
extern lv_obj_t * ui_IFSPanel;
void ui_event_IFSgraph(lv_event_t * e);
extern lv_obj_t * ui_IFSgraph;
void ui_event_IFSGraphLabels(lv_event_t * e);
extern lv_obj_t * ui_IFSGraphLabels;
void ui_event_IFSGraphLabel(lv_event_t * e);
extern lv_obj_t * ui_IFSGraphLabel;
void ui_event_IFSValueLabel(lv_event_t * e);
extern lv_obj_t * ui_IFSValueLabel;
extern lv_obj_t * ui_CWSettingsPanel;
extern lv_obj_t * ui_CWTitlePanel;
void ui_event_CWGoBackButton(lv_event_t * e);
extern lv_obj_t * ui_CWGoBackButton;
extern lv_obj_t * ui_CWTitleLabel;
void ui_event_CWGoForwardButton(lv_event_t * e);
extern lv_obj_t * ui_CWGoForwardButton;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Panel3;
void ui_event_KeyRadioStraight(lv_event_t * e);
extern lv_obj_t * ui_KeyRadioStraight;
void ui_event_KeyRadioIambicA(lv_event_t * e);
extern lv_obj_t * ui_KeyRadioIambicA;
void ui_event_KeyRadioIambicB(lv_event_t * e);
extern lv_obj_t * ui_KeyRadioIambicB;
extern lv_obj_t * ui_CWBodyPanel;
extern lv_obj_t * ui_CWMainBodyPanel;
extern lv_obj_t * ui_Panel11;
extern lv_obj_t * ui_Panel13;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_Label17;
extern lv_obj_t * ui_Panel12;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_Arc2;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_Label18;
extern lv_obj_t * ui_Panel14;
extern lv_obj_t * ui_Label14;
extern lv_obj_t * ui_Arc3;
extern lv_obj_t * ui_Label13;
extern lv_obj_t * ui_Label21;
extern lv_obj_t * ui_Panel15;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_Arc4;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_Label22;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Label7;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_CWFooterPanel;
void ui_event_CWGoHomeButton(lv_event_t * e);
extern lv_obj_t * ui_CWGoHomeButton;
extern lv_obj_t * ui_VFOTuningPanel;
extern lv_obj_t * ui_VFOTitlePanel;
extern lv_obj_t * ui_VFOTitleLabel;
extern lv_obj_t * ui_VFOBodyPanel;
extern lv_obj_t * ui_VFOLeftBodyPanel;
void ui_event_VFOGoBackButton(lv_event_t * e);
extern lv_obj_t * ui_VFOGoBackButton;
extern lv_obj_t * ui_VFOMainBodyPanel;
extern lv_obj_t * ui_VFORightBodyPanel;
extern lv_obj_t * ui_VFOGoForwardButton;
extern lv_obj_t * ui_VFOFooterPanel;
void ui_event_VFOGoHomeButton(lv_event_t * e);
extern lv_obj_t * ui_VFOGoHomeButton;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_rightarrow_png);    // assets\rightarrow.png
LV_IMG_DECLARE(ui_img_436403744);    // assets\att-graph.png
LV_IMG_DECLARE(ui_img_redindicator_png);    // assets\redindicator.png
LV_IMG_DECLARE(ui_img_2028451397);    // assets\ifs-graph.png
LV_IMG_DECLARE(ui_img_greenindicator_png);    // assets\greenindicator.png
LV_IMG_DECLARE(ui_img_leftarrow_png);    // assets\leftarrow.png
LV_IMG_DECLARE(ui_img_homebutton_png);    // assets\homebutton.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
