/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _AUTH_HMAC_H
#define _AUTH_HMAC_H

#include "Common.h"
#include <vector>

class BigNumber;

class HmacHash
{
    public:
        HmacHash() { }
        HmacHash(uint8 const* data, int length);
        ~HmacHash();

        void UpdateBigNumber(BigNumber* bn);
        void UpdateData(std::vector<uint8> const& data);
        void UpdateData(uint8 const* data, int length);

        void Finalize();

        uint8* GetDigest() { return m_digest; }
        static int constexpr GetLength() { return sizeof(m_digest); }

    private:
        typedef struct hmac_ctx_st HMAC_CTX;
        HMAC_CTX* m_ctx;
        uint8 m_digest[20]; // SHA_DIGEST_LENGTH
};
#endif
