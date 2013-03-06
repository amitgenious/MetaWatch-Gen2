//==============================================================================
//  Copyright 2011 Meta Watch Ltd. - http://www.MetaWatch.org/
// 
//  Licensed under the Meta Watch License, Version 1.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  
//      http://www.MetaWatch.org/licenses/license-1.0.html
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//==============================================================================

/******************************************************************************/
/*! \file LcdDriver.h
 *
 * DMA is used to transfer data to the LCD.
 */
/******************************************************************************/

#ifndef LCD_TASK_H
#define LCD_TASK_H

/*! Initialize spi peripheral and LCD pins */
void LcdPeripheralInit(void);

/*! Write a line to the LCD 
 *
 * \param pLcdMessage is a pointer to a Lcd Message
 */
void WriteLcdHandler(tLcdData* pLcdMessage);

/*! Clear the LCD */
void ClearLcd(void);

/*! Draw the display generated by the watch firmware
 *
 * \param pBuffer is a pointer to the buffer to draw
 * \note Pointer is char* but display buffer is assumed to be of type tLcdLine.
 * \param is the total number of lines to draw
 */
void UpdateMyDisplay(unsigned char *pBuffer,unsigned int TotalLines);


/*! Callback from the DMA interrupt service routing that lets LCD task know 
 * that the dma has finished
 */
void LcdDmaIsr(void);

/*! Write the command that puts the LCD into static mode for power savings */
void PutLcdIntoStaticMode(void);

#endif /* LCD_TASK_H */
