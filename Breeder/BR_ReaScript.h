/******************************************************************************
/ BR_ReaScript.h
/
/ Copyright (c) 2014 Dominik Martin Drzic
/ http://forum.cockos.com/member.php?u=27094
/ https://code.google.com/p/sws-extension
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/
#pragma once

/******************************************************************************
* ReaScript export                                                            *
******************************************************************************/
void*           BR_EnvAlloc (TrackEnvelope* envelope);
int             BR_EnvCountPoints (void* envelope);
bool            BR_EnvDeletePoint (void* envelope, int id);
int             BR_EnvFind (void* envelope, double position, double delta);
int             BR_EnvFindNext (void* envelope, double position);
int             BR_EnvFindPrevious (void* envelope, double position);
bool            BR_EnvFree (void* envelope, bool commit);
bool            BR_EnvGetPoint (void* envelope, int id, double* position, double* value, int* shape, bool* selected, double* bezier);
void            BR_EnvGetProperties (void* envelope, bool* active, bool* visible, bool* armed, bool* inLane, int* laneHeight, int* defaultShape, double* minValue, double* maxValue, double* centerValue, int* type);
bool            BR_EnvSetPoint (void* envelope, int id, double position, double value, int shape, bool selected, double bezier);
void            BR_EnvSetProperties (void* envelope, bool active, bool visible, bool armed, bool inLane, int laneHeight, int defaultShape);
double          BR_EnvValueAtPos (void* envelope, double position);
bool            BR_GetMediaSourceProperties (MediaItem_Take* take, bool* section, double* start, double* length, double* fade, bool* reverse);
void            BR_GetMouseCursorContext (char* window, char* segment, char* details, int char_sz);
TrackEnvelope*  BR_GetMouseCursorContext_Envelope (bool* takeEnvelope);
MediaItem*      BR_GetMouseCursorContext_Item ();
void*           BR_GetMouseCursorContext_MIDI (bool* inlineEditor, int* noteRow, int* ccLane, int* ccLaneVal, int* ccLaneId);
double          BR_GetMouseCursorContext_Position ();
MediaItem_Take* BR_GetMouseCursorContext_Take ();
MediaTrack*     BR_GetMouseCursorContext_Track ();
MediaItem*      BR_ItemAtMouseCursor (double* position);
bool            BR_MIDI_CCLaneRemove (void* midiEditor, int laneId);
bool            BR_MIDI_CCLaneReplace (void* midiEditor, int laneId, int newCC);
double          BR_PositionAtMouseCursor (bool checkRuler);
bool            BR_SetMediaSourceProperties (MediaItem_Take* take, bool section, double start, double length, double fade, bool reverse);
bool            BR_SetTakeSourceFromFile (MediaItem_Take* take, const char* filename, bool inProjectData);
bool            BR_SetTakeSourceFromFile2 (MediaItem_Take* take, const char* filename, bool inProjectData, bool keepSourceProperties);
MediaItem_Take* BR_TakeAtMouseCursor (double* position);
MediaTrack*     BR_TrackAtMouseCursor (int* context, double* position);

/******************************************************************************
* Big description!                                                            *
******************************************************************************/
#define BR_MOUSE_REASCRIPT_DESC "[BR] \
Get mouse cursor context. Each parameter returns information in a form of string as specified in the table below.\n\n\
To get more info on stuff that was found under mouse cursor see BR_GetMouseCursorContext_Envelope,\
BR_GetMouseCursorContext_Item, BR_GetMouseCursorContext_MIDI, BR_GetMouseCursorContext_Position, BR_GetMouseCursorContext_Take,\
BR_GetMouseCursorContext_Track \n\
Note that these functions will return every element found under mouse cursor. For example, if details is \"env_segment\",\
BR_GetMouseCursorContext_Item will still return valid item if it was under that envelope segment.\n\n\
<table border=\"2\">\
<tr><th style=\"width:100px\">Window</th> <th style=\"width:100px\">Segment</th> <th style=\"width:300px\">Details</th>           </tr>\
<tr><td rowspan=\"1\" align = \"center\"> unknown     </th> <td> \"\"        </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"4\" align = \"center\"> ruler       </th> <td> region_lane </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> marker_lane </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> tempo_lane  </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> timeline    </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"1\" align = \"center\"> transport   </th> <td> \"\"        </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"3\" align = \"center\"> tcp         </th> <td> track       </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> envelope    </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> empty       </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"2\" align = \"center\"> mcp         </th> <td> track       </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> empty       </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"3\" align = \"center\"> arrange     </th> <td> track       </td> <td> item, env_point, env_segment, empty </td> </tr>\
<tr>                                                        <td> envelope    </td> <td> env_point, env_segment, empty       </td> </tr>\
<tr>                                                        <td> empty       </td> <td> \"\"                                </td> </tr>\
<tr><td rowspan=\"5\" align = \"center\"> midi_editor </th> <td> unknown     </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> ruler       </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> piano       </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> notes       </td> <td> \"\"                                </td> </tr>\
<tr>                                                        <td> cc_lane     </td> <td> cc_selector, cc_lane                </td> </tr>\
</table>"