#include "VoiceAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

VoiceAction::VoiceAction(ApplicationManager * pApp):Action(pApp)
{
}

void VoiceAction::ReadActionParameters() 
{	
}

void VoiceAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	bool voice = pManager->getVoice();
	if (voice)
	{
		pOut->PrintMessage("Voice Switched OFF");
		pManager->setVoice(false);
	}
	else
	{
		pOut->PrintMessage("Voice Switched ON");
		pManager->setVoice(true);
	}
}

VoiceAction::~VoiceAction(void)
{
}
