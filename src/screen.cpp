#include "screen.hpp"
using std::string;
using std::to_string;


int selectedAuton = 1;
bool test1 = false;
bool test2 = false;
bool test3 = false;

//Main theme for display.
lv_theme_t * theme_main;

//Auton run page and countdown.
lv_obj_t *page;
lv_obj_t *label_cancel;

lv_obj_t *tab1;
lv_obj_t *tab2;

bool toggleAuton = false;


//Called when cancel auton button is pressed.
static lv_res_t cancel_auton_btn_press(lv_obj_t * btn) {
  //Deletes the page and all child objects.
  lv_obj_del(page);
  toggleAuton = false;

  return LV_RES_OK; /*Return OK if the button is not deleted*/
}


//Called when auton run button is pressed.
static lv_res_t run_auton_btn_press(lv_obj_t * btn) {
  //Creates page.
  page = lv_page_create(tab2, NULL);
  lv_obj_set_size(page, 460, 155);
  lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_page_set_sb_mode(page, LV_SB_MODE_OFF);

  /*Cancel button for run auton page*/
  lv_obj_t * btnCancel = lv_btn_create(page, NULL);
  lv_obj_set_size(btnCancel, 200, 50);
  lv_obj_align(btnCancel, page, LV_ALIGN_IN_TOP_MID, 0, 0);
  lv_btn_set_action(btnCancel, LV_BTN_ACTION_CLICK, cancel_auton_btn_press);

  /*Label for cancel auton*/
  lv_obj_t * label = lv_label_create(btnCancel, NULL);
  lv_label_set_text(label, "Cancel Auton");

  /*Displays auton that is about to run*/
  lv_obj_t * label_auton = lv_label_create(page, NULL);
  switch (selectedAuton) {
    case 1: lv_label_set_text(label_auton, "RED");
      break;
    case 2: lv_label_set_text(label_auton, "BLUE");
      break;
    case 3: lv_label_set_text(label_auton, "SKILLS");
      break;
    }
  lv_obj_align(label_auton, btnCancel, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

  /*Countdown until auton is run*/
  label_cancel = lv_label_create(page, NULL);
  lv_label_set_text(label_cancel, "Auton Starting In 5 Seconds.");
  lv_obj_align(label_cancel, label_auton, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

  delay(100);
  toggleAuton = true;


  return LV_RES_OK; /*Return OK if the button is not deleted*/
}


/*Called when a button from the button matrix is pressed*/
static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt) {
  //Changes the selected auton to the corresponding pressed button. Displays on controller.
  if (strcmp(txt, "Red") == 0) {
    selectedAuton = 1;
    // master.print(0, 0, "Red Auton   ");
  }
  else if (strcmp(txt, "Blue") == 0) {
    selectedAuton = 2;
    // master.print(0, 0, "Blue Auton  ");
  }
  else if (strcmp(txt, "Skills") == 0) {
    selectedAuton = 3;
    // master.print(0, 0, "Skills Auton");
  }

  return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}


static lv_res_t sw1_action(lv_obj_t *sw) {
  lv_sw_get_state(sw) ? test1 = true : test1 = false;


  return LV_RES_OK;
}


static lv_res_t sw2_action(lv_obj_t *sw) {
  lv_sw_get_state(sw) ? test2 = true : test2 = false;


  return LV_RES_OK;
}


static lv_res_t sw3_action(lv_obj_t *sw) {
  lv_sw_get_state(sw) ? test3 = true : test3 = false;


  return LV_RES_OK;
}


//Text object for displayed variables.
lv_obj_t * txt;

void runScreen() {
  // master.print(0, 0, "Red Auton");

  //Sets theme to alien.
  theme_main = lv_theme_alien_init(146, NULL);
  lv_theme_set_current(theme_main);

  /*Create a Tab view object*/
  lv_obj_t *tabview;
  tabview = lv_tabview_create(lv_scr_act(), NULL);
  lv_tabview_set_sliding(tabview, false);

  /*Add 2 tabs (the tabs are page (lv_page) and can be scrolled*/
  tab1 = lv_tabview_add_tab(tabview, "Debug Info");
  lv_page_set_sb_mode(tab1, LV_SB_MODE_OFF);
  tab2 = lv_tabview_add_tab(tabview, "Auton Selection");
  lv_page_set_sb_mode(tab2, LV_SB_MODE_OFF);

  //Creates box that conatins displayed variables.
  lv_obj_t * box1;
  box1 = lv_cont_create(tab1, NULL);
  lv_obj_set_size(box1, 460, 155);
  lv_obj_set_style(box1, &lv_style_pretty);
  lv_obj_align(box1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  //Adds the values to the box.
  txt = lv_label_create(box1, NULL);
  lv_obj_align(txt, box1, LV_ALIGN_IN_TOP_LEFT, 10, 1);

  /*Create a button descriptor string array*/
  static const char * btnm_map[] = {"Red", "Blue", "Skills", ""};

  /*Create a default button matrix*/
  lv_obj_t * btnm1 = lv_btnm_create(tab2, NULL);
  lv_btnm_set_map(btnm1, btnm_map);
  lv_btnm_set_toggle(btnm1, true, 0);
  lv_btnm_set_action(btnm1, btnm_action);
  lv_obj_set_size(btnm1, 460, 30);
  lv_obj_align(btnm1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  /*Copy the button and set toggled state. (The release action is copied too)*/
  lv_obj_t * btn1 = lv_btn_create(tab2, NULL);
  lv_obj_set_size(btn1, 130, 30);
  lv_obj_align(btn1, btnm1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, run_auton_btn_press);

  /*Add a label to the toggled button*/
  lv_obj_t *label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "Run");

  /*Create switches with labels*/
  lv_obj_t *sw2 = lv_sw_create(tab2, NULL);
  lv_obj_set_size(sw2, 60, 20);
  lv_obj_align(sw2, btnm1, LV_ALIGN_IN_BOTTOM_MID, 0, 110);
  lv_sw_set_action(sw2, sw2_action);
  lv_obj_t *sw2_label = lv_label_create(tab2, NULL);
  lv_label_set_text(sw2_label, "Test 2");
  lv_obj_align(sw2_label, sw2, LV_ALIGN_OUT_TOP_MID, 0, -10);

  lv_obj_t *sw1 = lv_sw_create(tab2, NULL);
  lv_obj_set_size(sw1, 60, 20);
  lv_obj_align(sw1, sw2, LV_ALIGN_OUT_LEFT_MID, -100, 0);
  lv_sw_set_action(sw1, sw1_action);
  lv_obj_t *sw1_label = lv_label_create(tab2, NULL);
  lv_label_set_text(sw1_label, "Test 1");
  lv_obj_align(sw1_label, sw1, LV_ALIGN_OUT_TOP_MID, 0, -10);

  lv_obj_t *sw3 = lv_sw_create(tab2, NULL);
  lv_obj_set_size(sw3, 60, 20);
  lv_obj_align(sw3, sw2, LV_ALIGN_OUT_RIGHT_MID, 100, 0);
  lv_sw_set_action(sw3, sw3_action);
  lv_obj_t *sw3_label = lv_label_create(tab2, NULL);
  lv_label_set_text(sw3_label, "Test 3");
  lv_obj_align(sw3_label, sw3, LV_ALIGN_OUT_TOP_MID, 0, -10);
}

float rightEncoder;
float leftEncoder;
float flipperEncoder;
float launcherEncoder;
float testValue;

void updateLineVariable(int line, float value) {
  switch (line){
    case 1: rightEncoder = value;
      break;
    case 2: leftEncoder = value;
      break;
    case 3: flipperEncoder = value;
      break;
    case 4: launcherEncoder = value;
  }

  lv_label_set_text(txt, (  "Right encoder: " + to_string(rightEncoder) + '\n' +
                            "Left encoder: " + to_string(leftEncoder) + '\n' +
                            "Flipper encoder: " + to_string(flipperEncoder) + '\n' +
                            "Launcher angle encoder: " + to_string(launcherEncoder) + '\n' +
                            "Selected Auton: " + to_string(selectedAuton) + '\n' +
                            "Test switches: " + to_string(test1) + " " + to_string(test2) +
                            " " + to_string(test3) + '\n' +
                            "Test" + '\n').c_str());
}

bool waitAuton = false;
long currentTime;
void startAuton() {
  if (toggleAuton) {
    if (!waitAuton) {
      currentTime = millis();
      waitAuton = true;
      printf("Setting time\n");
    }
    else
      lv_label_set_text(label_cancel,   ("Auton Starting In " +
                                        to_string(5 - (((int)millis() - (int)currentTime) / 1000)) +
                                        " Seconds.").c_str());

    if (currentTime < millis() - 5000) {
      toggleAuton = false;
      waitAuton = false;
      lv_obj_del(page);
      autonomous();
      printf("Starting auton\n");
    }
  }
  else
    waitAuton = false;
}
