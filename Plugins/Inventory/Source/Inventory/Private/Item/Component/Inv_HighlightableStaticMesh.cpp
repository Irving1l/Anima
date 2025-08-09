// Irving's project is aimed at finding a job.


#include "Item/Component/Inv_HighlightableStaticMesh.h"

void UInv_HighlightableStaticMesh::Highlight_Implementation()
{
	SetOverlayMaterial(HighlightMaterial);
}

void UInv_HighlightableStaticMesh::UnHighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
