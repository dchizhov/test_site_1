<?php

foreach ($data as $value):?>
    <div>
        <?= $value->title ?>
    </div>
    <div>
        <?= format_date($value->created) ?>
    </div>
<?php endforeach; ?>
