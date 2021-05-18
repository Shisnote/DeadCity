#include "DeadCity.h"

DeadCity::DeadCity() : m_Figure(Point(5, 1))
{
	m_GameField.Resize(14, 26);
	m_Canvas.Resize(26, 14);
}

void DeadCity::OnKeyPressed(int btnCode)
{
	m_Figure.Backup();
	switch (btnCode)
	{
	case 32: // Space
		m_Figure.Rotate();
		break;

	case 75: //Arrow Left
		m_Figure.MoveL();
		break;

	case 77: //Arrow Right
		m_Figure.MoveR();
		break;

	case 80: //Arrow Down
		m_Figure.Boost();
		break;

	default:
		break;

	}

	if (m_GameField.HasCollision(m_Figure)) {
		m_Figure.Restore();
	}
}

void DeadCity::Update(double dt)
{
	m_Figure.Backup();
	m_Figure.Update(dt);
	if (m_GameField.HasCollision(m_Figure)) {
		m_Figure.Restore();
		m_GameField.Merge(m_Figure);
		m_Figure = Point(5, 1);
		if (m_GameField.HasCollision(m_Figure))
		{
			m_End = true;
		}
	}

	m_Canvas.Clear();
	m_GameField.Draw(m_Canvas);
	m_Figure.Draw(m_Canvas);
	m_Canvas.Render();
}

bool DeadCity::End()
{
	return m_End;
}
