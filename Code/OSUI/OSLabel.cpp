// OSLabel.cpp
//------------------------------------------------------------------------------

// Includes
//------------------------------------------------------------------------------
#include "OSUI/PrecompiledHeader.h"
#include "OSLabel.h"

// OSUI
#include "OSUI/OSFont.h"
#include "OSUI/OSWindow.h"

// Core
#include "Core/Env/Assert.h"

// Defines
//------------------------------------------------------------------------------

// CONSTRUCTOR
//------------------------------------------------------------------------------
OSLabel::OSLabel( OSWindow * parentWindow ) :
    OSWidget( parentWindow ),
    m_Font( nullptr )
{
}

// SetFont
//------------------------------------------------------------------------------
void OSLabel::SetFont( OSFont * font )
{
    ASSERT( !m_Initialized ); // Change font after Init not currently supported
    m_Font = font;
}

// Init
//------------------------------------------------------------------------------
void OSLabel::Init( int32_t x, int32_t y, uint32_t w, uint32_t h, const char * labelText )
{
    #if defined( __WINDOWS__ )
        // Create control
        m_Handle = CreateWindowEx( WS_EX_TRANSPARENT, "STATIC", "", WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU , x, y, w, h, (HWND)m_Parent->GetHandle(), NULL, (HINSTANCE)m_Parent->GetHInstance(), NULL );

        // Set font
        SendMessage( (HWND)m_Handle, WM_SETFONT, (WPARAM)m_Font->GetFont(), NULL );

        // Set text
        SendMessage( (HWND)m_Handle, WM_SETTEXT, NULL, (LPARAM)labelText );
    #else
        (void)x;
        (void)y;
        (void)w;
        (void)h;
        (void)labelText;
    #endif

    OSWidget::Init();
}

//------------------------------------------------------------------------------