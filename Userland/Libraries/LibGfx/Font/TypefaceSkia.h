/*
 * Copyright (c) 2024, Aliaksandr Kalenik <kalenik.aliaksandr@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGfx/Font/Typeface.h>

namespace Gfx {

class TypefaceSkia : public Gfx::Typeface {
    AK_MAKE_NONCOPYABLE(TypefaceSkia);

public:
    static ErrorOr<NonnullRefPtr<TypefaceSkia>> load_from_buffer(ReadonlyBytes, int index = 0);

    virtual u32 glyph_count() const override;
    virtual u16 units_per_em() const override;
    virtual u32 glyph_id_for_code_point(u32 code_point) const override;
    virtual String family() const override;
    virtual u16 weight() const override;
    virtual u16 width() const override;
    virtual u8 slope() const override;

    virtual ReadonlyBytes buffer() const override { return m_buffer; }
    virtual unsigned ttc_index() const override { return m_ttc_index; }

    SkTypeface const* sk_typeface() const;

private:
    struct Impl;
    Impl& impl() const { return *m_impl; }
    NonnullOwnPtr<Impl> m_impl;

    explicit TypefaceSkia(NonnullOwnPtr<Impl>, ReadonlyBytes, int ttc_index = 0);

    ReadonlyBytes m_buffer;
    unsigned m_ttc_index { 0 };
};

}
