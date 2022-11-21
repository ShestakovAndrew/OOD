#pragma once
#include <variant>

#include "IImage.h"
#include "IParagraph.h"

using Item = std::variant<std::shared_ptr<IImage>, std::shared_ptr<IParagraph>>;