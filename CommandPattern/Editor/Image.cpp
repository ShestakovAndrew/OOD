#include "Image.h"
#include "ResizeImageCommand.h"
#include <string>
#include <random>

const std::string JPG = ".jpg";
const std::string PNG = ".png";
const std::string SVG = ".svg";

const std::string IMAGES_DIRECTORY = "images";

namespace
{
std::string CreateRandomName(size_t length)
{
	const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	std::random_device randomDevice;
	std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

	std::string result;

	for (std::size_t i = 0; i < length; ++i)
	{
		result += characters[distribution(randomDevice)];
	}

	return result;
}
} // namespace

CImage::CImage(Path const& path, int width, int height, ICommandSink& commandSink)
	: m_commandSink(commandSink)
{
	if (!IsImage(path) || !std::filesystem::exists(path))
	{
		throw std::invalid_argument("invalid image path");
	}
	if (width < 1 || height < 1 || width > 10000 || height > 10000)
	{
		throw std::invalid_argument("image size must be in [1; 10000]");
	}
	m_width = width;
	m_height = height;

	std::string newFileName = CreateRandomName(9);
	std::string resultPath = IMAGES_DIRECTORY + "/" + newFileName + path.extension().string();
	if (!std::filesystem::is_directory(IMAGES_DIRECTORY))
	{
		std::filesystem::create_directory(IMAGES_DIRECTORY);
	}

	std::filesystem::copy_file(path, resultPath);
	m_path = resultPath;
}

Path CImage::GetPath() const
{
	return m_path;
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	m_commandSink.SaveCommand(std::make_unique<CResizeImageCommand>(m_height, m_width, height, width));
}

void CImage::RemoveFile() noexcept
{
	try
	{
		std::filesystem::remove(m_path);
	}
	catch (...)
	{
	}
}

bool CImage::IsImage(Path const& path)
{
	auto extension = path.extension();
	if (extension == JPG || extension == PNG || extension == SVG)
	{
		return true;
	}
	return false;
}
