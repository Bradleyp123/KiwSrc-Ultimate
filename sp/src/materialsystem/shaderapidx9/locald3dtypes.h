#ifndef LOCALD3DTYPES_H
#define LOCALD3DTYPES_H

#ifdef _WIN32
#pragma once
#endif

#include <d3d11.h>
#include <d3dx11.h>

#if defined( DX10 ) && !defined( DX_TO_GL_ABSTRACTION )

// DirectX 10 code block remains unchanged

#endif // defined( DX10 ) && !defined( DX_TO_GL_ABSTRACTION )

#if defined( DX11 ) && !defined( DX_TO_GL_ABSTRACTION )

// DirectX 11 code block remains unchanged

#endif // defined( DX11 ) && !defined( DX_TO_GL_ABSTRACTION )

#if !defined( _X360 ) && !defined( DX_TO_GL_ABSTRACTION )
#ifdef _DEBUG
#define D3D_DEBUG_INFO 1
#endif
#endif

// DirectX 9 structures and typedefs

struct IDirect3DTexture9;
struct IDirect3DBaseTexture9;
struct IDirect3DCubeTexture9;
struct IDirect3D9;
struct IDirect3DDevice9;
struct IDirect3DSurface9;
struct IDirect3DIndexBuffer9;
struct IDirect3DVertexBuffer9;
struct IDirect3DVertexShader9;
struct IDirect3DPixelShader9;
struct IDirect3DVolumeTexture9;

typedef struct _D3DLIGHT9                D3DLIGHT9;
typedef struct _D3DADAPTER_IDENTIFIER9  D3DADAPTER_IDENTIFIER9;
typedef struct _D3DCAPS9                 D3DCAPS9;
typedef struct _D3DVIEWPORT9             D3DVIEWPORT9;
typedef struct _D3DMATERIAL9             D3DMATERIAL9;
typedef IDirect3DTexture9                IDirect3DTexture;
typedef IDirect3DBaseTexture9            IDirect3DBaseTexture;
typedef IDirect3DCubeTexture9            IDirect3DCubeTexture;
typedef IDirect3DVolumeTexture9          IDirect3DVolumeTexture;
typedef IDirect3DDevice9                 IDirect3DDevice;
typedef D3DMATERIAL9                     D3DMATERIAL;
typedef D3DLIGHT9                        D3DLIGHT;
typedef IDirect3DSurface9                IDirect3DSurface;
typedef D3DCAPS9                         D3DCAPS;
typedef IDirect3DIndexBuffer9            IDirect3DIndexBuffer;
typedef IDirect3DVertexBuffer9           IDirect3DVertexBuffer;
typedef IDirect3DPixelShader9            IDirect3DPixelShader;
typedef IDirect3DDevice                  *LPDIRECT3DDEVICE;
typedef IDirect3DIndexBuffer             *LPDIRECT3DINDEXBUFFER;
typedef IDirect3DVertexBuffer            *LPDIRECT3DVERTEXBUFFER;

// DirectX 9 class

class CDx9Types
{
public:
    typedef IDirect3DTexture9            IDirect3DTexture;
    typedef IDirect3DBaseTexture9        IDirect3DBaseTexture;
    typedef IDirect3DCubeTexture9        IDirect3DCubeTexture;
    typedef IDirect3DVolumeTexture9      IDirect3DVolumeTexture;
    typedef IDirect3DDevice9             IDirect3DDevice;
    typedef D3DMATERIAL9                 D3DMATERIAL;
    typedef D3DLIGHT9                    D3DLIGHT;
    typedef IDirect3DSurface9            IDirect3DSurface;
    typedef D3DCAPS9                     D3DCAPS;
    typedef IDirect3DIndexBuffer9        IDirect3DIndexBuffer;
    typedef IDirect3DVertexBuffer9       IDirect3DVertexBuffer;
    typedef IDirect3DPixelShader9        IDirect3DPixelShader;
    typedef IDirect3DDevice              *LPDIRECT3DDEVICE;
    typedef IDirect3DIndexBuffer         *LPDIRECT3DINDEXBUFFER;
    typedef IDirect3DVertexBuffer        *LPDIRECT3DVERTEXBUFFER;
};

// Definitions for tessellation support

#if defined( DX11 ) && !defined( DX_TO_GL_ABSTRACTION )

struct IDirect3D11HullShader
{
    ID3D11HullShader* m_pHullShader;
};

struct IDirect3D11DomainShader
{
    ID3D11DomainShader* m_pDomainShader;
};

typedef ID3D11HullShader IDirect3DVertexHullShader;
typedef ID3D11DomainShader IDirect3DVertexDomainShader;

#endif // defined( DX11 ) && !defined( DX_TO_GL_ABSTRACTION )

#endif // LOCALD3DTYPES_H
