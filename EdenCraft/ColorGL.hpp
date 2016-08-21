#pragma once

template <int S>
using Vector = float[S];

namespace Colors {
	using Color = Vector<3>;

	const Color BLACK = { 0.0f, 0.0f, 0.0f };
	const Color WHITE = { 1.0f, 1.0f, 1.0f };
	const Color DARK_GRAY = { 0.2f, 0.2f, 0.2f };
	const Color LIGHT_GRAY = { 0.8f, 0.8f, 0.8f };
	const Color RED = { 1.0f, 0.0f, 0.0f };
	const Color GREEN = { 0.0f, 1.0f, 0.0f };
	const Color BLUE = { 0.0f, 0.0f, 1.0f };
	const Color CYAN = { 0.0f, 1.0f, 1.0f };
	const Color YELLOW = { 1.0f, 1.0f, 1.0f };
}