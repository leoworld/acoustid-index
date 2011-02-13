// Acoustid Index -- Inverted index for audio fingerprints
// Copyright (C) 2011  Lukas Lalinsky
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ACOUSTID_FS_INPUT_STREAM_H_
#define ACOUSTID_FS_INPUT_STREAM_H_

#include <QSharedPointer>
#include "fs_file.h"
#include "buffered_input_stream.h"

namespace Acoustid {

class FSInputStream : public BufferedInputStream
{
public:
	explicit FSInputStream(const FSFileSharedPtr &file);
	~FSInputStream();

	int fileDescriptor() const;
	const FSFileSharedPtr &file() const;

	static FSInputStream *open(const QString &fileName);

protected:
	size_t read(uint8_t *data, size_t offset, size_t length);

private:
	FSFileSharedPtr m_file;
};

}

#endif

