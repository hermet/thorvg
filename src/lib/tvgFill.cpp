/*
 * Copyright (c) 2020-2021 Samsung Electronics Co., Ltd. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "tvgFill.h"

/************************************************************************/
/* Internal Class Implementation                                        */
/************************************************************************/


/************************************************************************/
/* External Class Implementation                                        */
/************************************************************************/

Fill::Fill():pImpl(new Impl())
{
}


Fill::~Fill()
{
    delete(pImpl);
}


Result Fill::colorStops(const ColorStop* colorStops, uint32_t cnt) noexcept
{
    if (cnt == 0) {
        if (pImpl->colorStops) {
            free(pImpl->colorStops);
            pImpl->colorStops = nullptr;
            pImpl->cnt = cnt;
        }
        return Result::Success;
    }

    if (pImpl->cnt != cnt) {
        pImpl->colorStops = static_cast<ColorStop*>(realloc(pImpl->colorStops, cnt * sizeof(ColorStop)));
    }

    pImpl->cnt = cnt;
    memcpy(pImpl->colorStops, colorStops, cnt * sizeof(ColorStop));

    return Result::Success;
}


uint32_t Fill::colorStops(const ColorStop** colorStops) const noexcept
{
    if (colorStops) *colorStops = pImpl->colorStops;

    return pImpl->cnt;
}


Result Fill::spread(FillSpread s) noexcept
{
    pImpl->spread = s;

    return Result::Success;
}


FillSpread Fill::spread() const noexcept
{
    return pImpl->spread;
}


Fill* Fill::duplicate() const noexcept
{
    return pImpl->duplicate();
}